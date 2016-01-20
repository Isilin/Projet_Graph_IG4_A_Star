#include "DisplayGrid.hpp"

#include "Texture.inl"

using namespace app::sys;
using namespace app::def;

DisplayGrid::DisplayGrid(): System()
{
}


DisplayGrid::~DisplayGrid()
{
}

void app::sys::DisplayGrid::update(std::shared_ptr<core::com::Message> messageIn)
{
	if (messageIn->getMessage() == _CHANGE_RENDER_) {
		std::vector<int> elements = this->getComponents(_TEXTURE_);
		for (auto i : elements) {
			auto texture = this->getComponent<TextureID>(_TEXTURE_, i);
		}
	}
}

void app::sys::DisplayGrid::render()
{
}
