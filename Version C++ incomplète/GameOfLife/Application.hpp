#pragma once

#include <memory>

#include "Office.hpp"
#include "EntityManager.hpp"
#include "Engine.hpp"
#include "Communicable.hpp"
#include "Limiter.hpp"
#include "FiniteStateMachine.hpp"
#include "ComponentManager.hpp"
#include "ResourceManager.hpp"

#include "Event.inl"

namespace core
{
	class Application: public core::Limiter
	{
	public:
		Application();
		~Application();

		void initialize();
		void run();

	private:
		std::shared_ptr<core::com::Office> office;
		std::shared_ptr<std::mutex> lockOffice;

		std::shared_ptr<core::ecs::ComponentManager> cm;
		std::shared_ptr<std::mutex> lockCm;

		std::shared_ptr<core::ecs::EntityManager> em;
		std::shared_ptr<std::mutex> lockEm;

		std::shared_ptr<core::ecs::ResourceManager> rm;
		std::shared_ptr<std::mutex> lockRm;

		std::shared_ptr<core::ecs::FiniteStateMachine> fsm;

		std::map<app::def::AccountID, std::shared_ptr<core::ecs::Engine>> engines;
		bool running;

		sf::RenderWindow window;
		std::shared_ptr<sf::RenderTexture> renderer;
		std::shared_ptr<std::mutex> lockRenderer;
		std::shared_ptr<std::queue<app::def::Event>> waitingEvents;
		std::shared_ptr<std::mutex> lockEvents;
	};
}
