#pragma once

#include "Engine.hpp"

namespace app
{
	namespace eng
	{
		class LogicEngine : public core::ecs::Engine
		{
		public:
			LogicEngine(const bool activeIn, const int refreshRateIn);
			~LogicEngine();

			virtual void initialize();
		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn);
			virtual void update();
			virtual void render();
		};
	}
}