#pragma once

#include <unordered_map>
#include <iostream>
#include <vector>

#include "Account.hpp"
#include "Component.hpp"
#include "AbstractMessage.hpp"

#include "Component.inl"

namespace core
{
	namespace ecs
	{
		struct TSComponent {
			std::shared_ptr<IComponent> component;
			bool access;
		};

		class ComponentManager : public core::com::Account
		{
		public:
			ComponentManager();
			~ComponentManager();

			template <class T> void addComponent(const T& valueIn, const app::def::ComponentID typeIn, const int idEntityIn);
			void deleteComponent(const app::def::ComponentID typeIn, const int idEntityIn);

			template <class T> T& getComponent(const app::def::ComponentID typeIn, const int idEntityIn) const;
			template <class T> bool setComponent(const T& valueIn, const app::def::ComponentID typeIn, const int idEntityIn);

			int getNumberOfComponents(const app::def::ComponentID typeIn) const;
			const std::vector<int>& getComponents(const app::def::ComponentID typeIn) const;

		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn);

		private:
			std::unordered_map < app::def::ComponentID, std::unordered_map<int, TSComponent>> components;

			void lockComponent(const app::def::ComponentID typeIn, const int idEntityIn);
			void unlockComponent(const app::def::ComponentID typeIn, const int idEntityIn);
		};

		template <class T>
		void core::ecs::ComponentManager::addComponent(const T& valueIn, app::def::ComponentID typeIn, const int idEntityIn)
		{
			if (this->components.find(typeIn) == this->components.end()) {
				this->components[typeIn] = std::unordered_map<int, TSComponent>();
			}

			if (this->components[typeIn].find(idEntityIn) == this->components[typeIn].end()) {
				this->components[typeIn][idEntityIn] = TSComponent{ std::shared_ptr<core::ecs::Component<T>>(new core::ecs::Component<T>(valueIn)), true };
			}
			else {
				throw new std::exception("This entity already has a component with this type !");
			}
		}

		template <class T>
		T&  core::ecs::ComponentManager::getComponent(const app::def::ComponentID typeIn, const int idEntityIn) const
		{
			T tmp;
			if (this->components.find(typeIn) == this->components.end()) {
				throw new std::exception("This component's type is not registered.");
			}
			else if (this->components[typeIn].find(idEntityIn) == this->components[typeIn].end()) {
				throw new std::exception("There is not entity registered for this component's type.");
			}
			else if (this->components[typeIn][idEntityIn].access) {
				this->lockComponent(typeIn, idEntityIn);
				if (typeid(this->components[typeIn][idEntityIn].component) == typeid(T)) {
					tmp = std::static_pointer_cast<Component<T>>(this->components[typeIn][idEntityIn].component)->getValue();
				}
				else {
					throw new std::exception("Incorrect type casting for this component.");
				}
				this->unlockComponent(typeIn, idEntityIn);
			}
			else {
				throw new std::exception("Error during access to a component");
			}
			return tmp;
		}

		template<class T>
		bool core::ecs::ComponentManager::setComponent(const T& valueIn, const app::def::ComponentID typeIn, const int idEntityIn)
		{
			if (this->components.find(typeIn) == this->components.end()) {
				throw new std::exception("This component's type is not registered.");
			}
			else if (this->components[typeIn].find(idEntityIn) == this->components[typeIn].end()) {
				throw new std::exception("There is not entity registered for this component's type.");
			}
			else if (this->components[typeIn][idEntityIn].access) {
				this->lockComponent(typeIn, idEntityIn);
				if (typeid(T) == typeid(this->components[typeIn][idEntityIn].component)) {
					this->components[typeIn][idEntityIn].component = valueIn;
				}
				this->unlockComponent(typeIn, idEntityIn);
				return true;
			}
			else {
				return false;
			}
		}
	}
}