#include "ComponentUser.hpp"


using namespace core::ecs;

std::weak_ptr<ComponentManager> ComponentUser::cm;
std::shared_ptr<std::mutex> ComponentUser::lockCm = nullptr;

std::weak_ptr<EntityManager> ComponentUser::em;
std::shared_ptr<std::mutex> ComponentUser::lockEm = nullptr;

std::weak_ptr<ResourceManager> ComponentUser::rm;
std::shared_ptr<std::mutex> ComponentUser::lockRm = nullptr;

void core::ecs::ComponentUser::deleteComponent(const app::def::ComponentID typeIn, const int idEntityIn)
{
	ComponentUser::lockCm->lock();
	auto tmpCM = ComponentUser::cm.lock();
	tmpCM->deleteComponent(typeIn, idEntityIn);
	ComponentUser::lockCm->unlock();
}

int core::ecs::ComponentUser::addEntity()
{
	int id = 0;
	ComponentUser::lockEm->lock();
	auto tmpEM = ComponentUser::em.lock();
	id = tmpEM->addEntity();
	ComponentUser::lockEm->unlock();
	return id;
}

void core::ecs::ComponentUser::setComponentManager(std::weak_ptr<ComponentManager> cmIn, std::shared_ptr<std::mutex> lockCmIn)
{
	ComponentUser::cm = cmIn;
	ComponentUser::lockCm = lockCmIn;
}

void core::ecs::ComponentUser::setEntityManager(std::weak_ptr<EntityManager> emIn, std::shared_ptr<std::mutex> lockEmIn)
{
	ComponentUser::em = emIn;
	ComponentUser::lockEm = lockEmIn;
}

void core::ecs::ComponentUser::setResourceManager(std::weak_ptr<ResourceManager> rmIn, std::shared_ptr<std::mutex> lockRmIn)
{
	ComponentUser::rm = rmIn;
	ComponentUser::lockRm = lockRmIn;
}

int core::ecs::ComponentUser::getNbComponents(const app::def::ComponentID typeIn) const
{
	int res = 0;
	this->lockCm->lock();
	auto tmpCM = ComponentUser::cm.lock();
	res = tmpCM->getNumberOfComponents(typeIn);
	this->lockEm->unlock();
	return res;
}

const std::vector<int>& core::ecs::ComponentUser::getComponents(const app::def::ComponentID typeIn) const
{
	std::vector<int> ids;
	this->lockCm->lock();
	auto tmpCM = ComponentUser::cm.lock();
	ids = tmpCM->getComponents(typeIn);
	this->lockEm->unlock();
	return ids;
}
