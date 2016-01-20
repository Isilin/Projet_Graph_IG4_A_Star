#include "EntityManager.hpp"

#include "HeavyMessage.hpp"
#include "DataType.inl"

#include <iostream>

using namespace core::ecs;
using namespace core::com;
using namespace app::def;
using namespace app::ent;

EntityManager::EntityManager(): Account(_EM_), freeId(), entities()
{
	this->freeId.push(0);
}


EntityManager::~EntityManager()
{
	for (auto id : this->entities) {
		this->broadcastDeletingEntity(id);
	}
}

int EntityManager::addEntity()
{
	int id = this->freeId.front();
	this->freeId.pop();
	this->entities.push_back(id);
	if (this->freeId.empty()) {
		this->freeId.push(id + 1);
	}
	return this->entities.back();
}

void EntityManager::deleteEntity(const int idIn)
{
	std::vector<int>::const_iterator entity = std::find(this->entities.begin(), this->entities.end(), idIn);
	if (entity != this->entities.end()) {
		this->entities.erase(entity);
		this->broadcastDeletingEntity(*entity);
	}
	else {
		throw std::exception("Out of bound vector.");
	}
}

void EntityManager::deleteEntities(const std::vector<int>& listIdIn)
{
	for (auto id : listIdIn) {
		this->deleteEntity(id);
	}
}

void EntityManager::process(std::shared_ptr<AbstractMessage> messageIn)
{
	// TODO use this code
	/*
	if (messageIn->getMessage() == _CREATE_CASE_) {
		auto tmpMessage = std::static_pointer_cast<HeavyMessage<Case>>(messageIn);
		int idEntity = this->freeId.front();
		this->addEntity();
	}
	*/
}

void EntityManager::broadcastDeletingEntity(const int idIn)
{
	std::shared_ptr<AbstractMessage> message(new HeavyMessage<int>(_DELETE_ENTITY_, idIn));
	this->broadcast(message);
}
