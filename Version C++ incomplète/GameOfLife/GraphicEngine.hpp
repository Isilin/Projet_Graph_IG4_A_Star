#pragma once

#include "Engine.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace app
{
	namespace eng
	{
		class GraphicEngine : public core::ecs::Engine
		{
		public:
			GraphicEngine(const bool activeIn, const int refreshRateIn, std::weak_ptr<sf::RenderTexture> rendererIn, 
							std::shared_ptr<std::mutex> lockRendererIn);
			~GraphicEngine();

			virtual void initialize();

		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn);
			virtual void update();
			virtual void render();

		private:
			std::shared_ptr<std::string> screenBuffer;
			std::weak_ptr<sf::RenderTexture> renderer;
			std::shared_ptr<std::mutex> lockRenderer;
		};
	}
}