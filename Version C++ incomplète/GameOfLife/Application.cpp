#include "Application.hpp"

#include <iostream>
#include <thread>
#include <ctime>

#include "GraphicEngine.hpp"
#include "LogicEngine.hpp"
#include "ComponentUser.hpp"

using namespace sf;
using namespace core;
using namespace core::com;
using namespace core::ecs;
using namespace app::eng;
using namespace app::def;

Application::Application() :
	Limiter(60), office(new Office()), lockOffice(new std::mutex()), cm(nullptr), lockCm(new std::mutex()), em(nullptr), lockEm(new std::mutex()),
	rm(nullptr), lockRm(new std::mutex()), fsm(nullptr), engines(), running(true), window(), renderer(new sf::RenderTexture()),
	lockRenderer(new std::mutex()), waitingEvents(new std::queue<app::def::Event>()), lockEvents(new std::mutex)
{
	Communicable::setOffice(this->office, this->lockOffice);

	this->cm = std::shared_ptr<ComponentManager>(new ComponentManager());
	ComponentUser::setComponentManager(this->cm, this->lockCm);

	this->em = std::shared_ptr<EntityManager>(new EntityManager());
	ComponentUser::setEntityManager(this->em, this->lockEm);

	this->rm = std::shared_ptr<ResourceManager>(new ResourceManager());
	ComponentUser::setResourceManager(this->rm, this->lockRm);

	this->fsm = std::shared_ptr<FiniteStateMachine>(new FiniteStateMachine());

	this->engines[_GRAPHIC_] = std::shared_ptr<Engine>(new GraphicEngine(true, 1, renderer, lockRenderer));
	this->engines[_LOGIC_] = std::shared_ptr<Engine>(new LogicEngine(true, 1));

	this->window.create(VideoMode(800, 600), "My window");
}

Application::~Application()
{
}

void Application::initialize()
{
	std::cout << "Initializing application ..." << std::endl;
	// TODO initialize application and memory loading

	for (auto it : this->engines) {
		it.second->initialize();
	}
}

void Application::run()
{
	std::cout << "Running application ..." << std::endl;
	std::vector<std::thread> engineThreads;
	for (auto it : this->engines) {
		engineThreads.push_back(std::thread(&Engine::run, it.second));
	}

	while (this->fsm->getCurrentState() != _STOP_) {
		this->begin();

		if (this->window.isOpen()) {
			sf::Event event;
			while (this->window.pollEvent(event))
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
				if (event.type == sf::Event::Closed) {
					this->window.close();
				}
				else if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Escape) {
						this->window.close();
					}
				}
			}
		}

		this->lockEm->lock();
		this->em->processMessages();
		this->lockEm->unlock();

		this->lockCm->lock();
		this->cm->processMessages();
		this->lockCm->unlock();

		this->fsm->processMessages();

		this->wait();

		this->lockRenderer->lock();
		this->window.clear();
		this->window.draw(sf::Sprite(this->renderer->getTexture()));
		this->window.display();
		this->lockRenderer->unlock();
	}

	// synchronisation before closing application
	for (unsigned short int i = 0; i < engineThreads.size(); i++) {
		engineThreads[i].join();
	}
}
