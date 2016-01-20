#include "LogicEngine.hpp"

#include <utility>
#include <iostream>

#include "Parser.hpp"
#include "Message.hpp"

using namespace core::ecs;
using namespace app::eng;
using namespace app::sys;
using namespace app::def;
using namespace core::com;

LogicEngine::LogicEngine(const bool activeIn, const int refreshRateIn): Engine(activeIn, refreshRateIn, _LOGIC_)
{
}


LogicEngine::~LogicEngine()
{
}

void app::eng::LogicEngine::initialize()
{
	this->systems.insert(std::make_pair(_PARSER_, std::unique_ptr<System>(new Parser("map.bmp"))));
	this->systems[_PARSER_]->update(std::shared_ptr<Message>(new Message(_LOAD_FILE_)));
}

void app::eng::LogicEngine::process(std::shared_ptr<core::com::AbstractMessage> messageIn)
{
}

void app::eng::LogicEngine::update()
{
}

void app::eng::LogicEngine::render()
{
}
