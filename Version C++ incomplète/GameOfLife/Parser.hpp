#pragma once

#include "System.hpp"

namespace app
{
	namespace sys
	{
		class Parser : public core::ecs::System
		{
		public:
			Parser(const std::string& pathIn);
			~Parser();

			virtual void update(std::shared_ptr<core::com::Message> messageIn);
			virtual void render();

		private:
			std::string path;
		};
	}
}

