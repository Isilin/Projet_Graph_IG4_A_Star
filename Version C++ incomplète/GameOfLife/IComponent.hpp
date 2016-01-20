#pragma once

#include <memory>

#include "AbstractMessage.hpp"

namespace core
{
	namespace ecs
	{
		class IComponent
		{
		public:
			virtual ~IComponent() {}
		};
	}
}