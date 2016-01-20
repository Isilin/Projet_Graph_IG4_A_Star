#pragma once

#include <memory>

#include "Account.hpp"
#include "System.hpp"
#include "Limiter.hpp"
#include "System.inl"

namespace core
{
	namespace ecs
	{
		class Engine : public core::com::Account, public core::Limiter
		{
		public:
			Engine(const bool activeIn, const int refreshRateIn, const int idAccountIn);
			virtual ~Engine();

			virtual void initialize() = 0;
			void run();

		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn) = 0;
			virtual void update() = 0;
			virtual void render() = 0;

			std::map<app::def::SystemID, std::unique_ptr<System>> systems;

		private:
			bool active;
		};
	}
}