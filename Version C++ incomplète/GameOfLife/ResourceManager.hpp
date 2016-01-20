#pragma once

#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "Resource.inl"

namespace core
{
	namespace ecs
	{
		class ResourceManager
		{
		public:
			ResourceManager();
			~ResourceManager();

		private:
			std::unordered_map<app::def::ResourceID, sf::Texture> textures;
		};

	}
}

