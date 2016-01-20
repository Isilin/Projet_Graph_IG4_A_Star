#include "ComponentManager.hpp"

#include "OfficeAccount.inl"

using namespace core::ecs;
using namespace app::def;

ComponentManager::ComponentManager(): Account(_CM_), components()
{
}


ComponentManager::~ComponentManager()
{
}

void core::ecs::ComponentManager::deleteComponent(const app::def::ComponentID typeIn, const int idEntityIn)
{
	if (this->components.find(typeIn) != this->components.end()) {
		if (this->components[typeIn].find(idEntityIn) != this->components[typeIn].end()) {
			this->components[typeIn].erase(this->components[typeIn].find(idEntityIn));
		}
	}
}

int core::ecs::ComponentManager::getNumberOfComponents(const app::def::ComponentID typeIn) const
{
	if (this->components.find(typeIn) != this->components.end()) {
		return this->components.at(typeIn).size();
	}
	else {
		return 0;
	}
}

const std::vector<int>& core::ecs::ComponentManager::getComponents(const app::def::ComponentID typeIn) const
{
	std::vector<int> ids;
	for (auto it : this->components.at(typeIn)) {
		ids.push_back(it.first);
	}
	return ids;
}

void core::ecs::ComponentManager::process(std::shared_ptr<core::com::AbstractMessage> messageIn)
{
}

void core::ecs::ComponentManager::lockComponent(const app::def::ComponentID typeIn, const int idEntityIn)
{
	this->components[typeIn][idEntityIn].access = false;
}

void core::ecs::ComponentManager::unlockComponent(const app::def::ComponentID typeIn, const int idEntityIn)
{
	this->components[typeIn][idEntityIn].access = true;
}
