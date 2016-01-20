#include <iostream>

#include "Application.hpp"

using namespace core;

// TODO implements factory way with registering needing elements (with using Instanciator <class Base, class Fille>)

int main()
{
	try {
		std::shared_ptr<Application> app(new Application());
		app->initialize();
		app->run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}