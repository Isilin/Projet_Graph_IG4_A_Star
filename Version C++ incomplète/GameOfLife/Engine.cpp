#include "Engine.hpp"

#include <ctime>

using namespace core::ecs;

Engine::Engine(const bool activeIn, const int fpsIn, const int idAccountIn): 
	Account(idAccountIn), Limiter(fpsIn), systems(), active(activeIn)
{
}


Engine::~Engine()
{
}

void Engine::run()
{
	while (this->active) {
		this->begin();

		this->processMessages();
		this->update();
		this->render();

		this->wait();
	}
}
