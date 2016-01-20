#pragma once

#include "System.hpp"

namespace app
{
	namespace sys
	{
		class DisplayGrid : public core::ecs::System
		{
		public:
			DisplayGrid();
			~DisplayGrid();

			virtual void update(std::shared_ptr<core::com::Message> messageIn);
			virtual void render();
		};
	}
}

