#include "Parser.hpp"

#include <iostream>

#include "Message.inl"
#include "HeavyMessage.hpp"
#include "Bitmap.hpp"
#include "DataType.inl"
#include "Texture.inl"

using namespace app::sys;
using namespace core::com;
using namespace app::def;
using namespace app::ent;
using namespace vdr;

Parser::Parser(const std::string& pathIn): System(), path(pathIn)
{
}

Parser::~Parser()
{
}

void app::sys::Parser::update(std::shared_ptr<Message> messageIn)
{
	std::shared_ptr<Bitmap> bmp = nullptr;
	switch (messageIn->getMessage()) {
	case _LOAD_FILE_:
		bmp = std::shared_ptr<Bitmap>(new Bitmap(this->path.c_str()));
		for (int j = 0; j < bmp->getHeight(); j++) {
			for (int i = 0; i < bmp->getHeight(); i++) {
				std::vector<unsigned int> pixel = bmp->getPixel(i, j);
				int id = this->addEntity();
				this->addComponent<Position>(Position{ i, j }, _POSITION_, id);
				if (pixel[0] == 0 && pixel[1] == 255 && pixel[2] == 0) {
					std::cout << "H";
					this->addComponent<int>(5, _CROSSING_TIME_, id);
					this->addComponent<TextureID>(_GRASS_TEXT_, _TEXTURE_, id);
				}
				else if (pixel[0] == 0 && pixel[1] == 128 && pixel[2] == 0) {
					std::cout << "F";
					this->addComponent<int>(5, _CROSSING_TIME_, id);
					this->addComponent<TextureID>(_FOREST_TEXT_, _TEXTURE_, id);
				}
				else if (pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 255) {
					std::cout << "E";
					this->addComponent<int>(5, _CROSSING_TIME_, id);
					this->addComponent<TextureID>(_WATER_TEXT_, _TEXTURE_, id);
				}
				else if (pixel[0] == 128 && pixel[1] == 64 && pixel[2] == 0) {
					std::cout << "P";
					this->addComponent<int>(5, _CROSSING_TIME_, id);
					this->addComponent<TextureID>(_BRIDGE_TEXT_, _TEXTURE_, id);
				}
				else if (pixel[0] == 128 && pixel[1] == 128 && pixel[2] == 128) {
					std::cout << "M";
					this->addComponent<int>(5, _CROSSING_TIME_, id);
					this->addComponent<TextureID>(_WALL_TEXT_, _TEXTURE_, id);
				}
				else if (pixel[0] == 192 && pixel[1] == 192 && pixel[2] == 192) {
					std::cout << "C";
					this->addComponent<int>(5, _CROSSING_TIME_, id);
					this->addComponent<TextureID>(_WAY_TEXT_, _TEXTURE_, id);
				}
				else {
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
		this->sendMessage(std::shared_ptr<Message>(new Message(_CHANGE_RENDER_)), _GRAPHIC_);
		break;
	case _SAVE_FILE_:
		break;
	case _CHANGE_FILE_:
		try {
			auto tmpMessage = std::dynamic_pointer_cast<HeavyMessage<std::string>>(messageIn);
		}
		catch (const std::exception& e) {
			std::cerr << "This message is corrupted. Check its content." << e.what() << std::endl;
		}
		break;
	default:
		break;
	}
}

void app::sys::Parser::render()
{
}
