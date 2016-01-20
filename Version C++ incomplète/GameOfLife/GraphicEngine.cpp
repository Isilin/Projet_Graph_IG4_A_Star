#include "GraphicEngine.hpp"

#include <iostream>
#include <windows.h>

using namespace sf;
using namespace app::eng;
using namespace core::ecs;
using namespace app::def;
using namespace core::com;

GraphicEngine::GraphicEngine(const bool activeIn, const int fpsIn, std::weak_ptr<sf::RenderTexture> renderererIn,
	std::shared_ptr<std::mutex> lockRendererIn):
	Engine(activeIn, fpsIn, _GRAPHIC_), screenBuffer(new std::string()), renderer(renderererIn), lockRenderer(lockRendererIn)
{
}


GraphicEngine::~GraphicEngine()
{
}

void app::eng::GraphicEngine::initialize()
{
	system("mode con lines=40 cols=50");
}

void app::eng::GraphicEngine::process(std::shared_ptr<AbstractMessage> messageIn)
{
	if (messageIn->getMessage() == _CHANGE_RENDER_) {

	}
}

void app::eng::GraphicEngine::update()
{
}

void app::eng::GraphicEngine::render()
{
	// system("cls");

	this->lockRenderer->lock();
	auto tmpRenderer = this->renderer.lock();
	tmpRenderer->clear(sf::Color(0, 0, 0));
	// TODO draw
	this->lockRenderer->unlock();

	// draw;
}