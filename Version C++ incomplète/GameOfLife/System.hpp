#pragma once

#include <map>
#include <memory>

#include "IComponent.hpp"
#include "Component.inl"
#include "ComponentUser.hpp"
#include "Message.hpp"

namespace core
{
	namespace ecs
	{
		class System : public ComponentUser, public core::com::Communicable
		{
		public:
			System();
			virtual ~System();

			virtual void update(std::shared_ptr<core::com::Message> messageIn) = 0;
			virtual void render() = 0;

		protected:
		};
	}
}