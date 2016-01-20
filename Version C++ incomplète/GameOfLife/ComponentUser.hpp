#pragma once

#include <memory>
#include <iostream>

#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "ResourceManager.hpp"

namespace core
{
	namespace ecs
	{
		class ComponentUser
		{
		public:
			template <class T> void addComponent(const T& valueIn, const app::def::ComponentID typeIn, const int idEntityIn);
			void deleteComponent(const app::def::ComponentID typeIn, const int idEntityIn);

			template <class T> T& getComponent(const app::def::ComponentID typeIn, const int idEntityIn) const;
			template <class T> bool setComponent(const T& valueIn, const app::def::ComponentID typeIn, const int idEntityIn);

			int addEntity();

			static void setComponentManager(std::weak_ptr<ComponentManager> cmIn, std::shared_ptr<std::mutex> lockCmIn);
			static void setEntityManager(std::weak_ptr<EntityManager> emIn, std::shared_ptr<std::mutex> lockEmIn);
			static void setResourceManager(std::weak_ptr<ResourceManager> rmIn, std::shared_ptr<std::mutex> lockRmIn);

			int getNbComponents(const app::def::ComponentID typeIn) const;
			const std::vector<int>& getComponents(const app::def::ComponentID typeIn) const;

		private:
			static std::weak_ptr<ComponentManager> cm;
			static std::shared_ptr<std::mutex> lockCm;

			static std::weak_ptr<EntityManager> em;
			static std::shared_ptr<std::mutex> lockEm;

			static std::weak_ptr<ResourceManager> rm;
			static std::shared_ptr<std::mutex> lockRm;
		};

		template<class T>
		void ComponentUser::addComponent(const T & valueIn, const app::def::ComponentID typeIn, const int idEntityIn)
		{
			ComponentUser::lockCm->lock();
			auto tmpCM = ComponentUser::cm.lock();
			try {
				tmpCM->addComponent<T>(valueIn, typeIn, idEntityIn);
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			ComponentUser::lockCm->unlock();
		}

		template<class T>
		T & ComponentUser::getComponent(const app::def::ComponentID typeIn, const int idEntityIn) const
		{
			T res;
			ComponentUser::lockCm->lock();
			auto tmpCM = ComponentUser::cm.lock();
			res = tmpCM->getComponent<T>(typeIn, idEntityIn);
			ComponentUser::lockCm->unlock();
			return res;
		}
		template<class T>
		bool ComponentUser::setComponent(const T & valueIn, const app::def::ComponentID typeIn, const int idEntityIn)
		{
			bool res;
			ComponentUser::lockCm->lock();
			auto tmpCM = ComponentUser::cm.lock();
			res = tmpCM->setComponent<T>(valueIn, typeIn, idEntityIn);
			ComponentUser::lockCm->unlock();
			return res;
		}
	}
}
