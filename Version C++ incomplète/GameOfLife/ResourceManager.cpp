#include "ResourceManager.hpp"

using namespace core::ecs;
using namespace app::def;

ResourceManager::ResourceManager(): textures()
{
	this->textures[_GRASS_] = sf::Texture();
	this->textures[_GRASS_].loadFromFile("grass.png");

	this->textures[_FOREST_] = sf::Texture();
	this->textures[_FOREST_].loadFromFile("forest_improved.png");

	this->textures[_WALL_] = sf::Texture();
	this->textures[_WALL_].loadFromFile("wall.png");

	this->textures[_BRIDGE_] = sf::Texture();
	this->textures[_BRIDGE_].loadFromFile("bridge.png");

	this->textures[_WATER_] = sf::Texture();
	this->textures[_WATER_].loadFromFile("water.png");

	this->textures[_WAY_] = sf::Texture();
	this->textures[_WAY_].loadFromFile("way.png");
}


ResourceManager::~ResourceManager()
{
}
