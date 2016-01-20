#include "Limiter.hpp"

#include <thread>

using namespace core;

Limiter::Limiter(const int fpsIn): start(), end(), fps(fpsIn)
{
}

Limiter::~Limiter()
{
}

void Limiter::begin()
{
	this->start = std::clock();
}

void Limiter::wait()
{
	this->end = std::clock();
	auto delta = 1000 * (this->end - this->start) / CLOCKS_PER_SEC;
	delta = (1000 / this->fps) - delta;
	if (delta > 0) {
		std::this_thread::sleep_for(std::chrono::duration<long, std::milli>(delta));
	}
}
