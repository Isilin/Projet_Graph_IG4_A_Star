#pragma once

#include <ctime>

namespace core
{
	class Limiter
	{
	public:
		Limiter(const int fpsIn);
		virtual ~Limiter();

		void begin();
		void wait();

	private:
		std::clock_t start;
		std::clock_t end;
		int fps;
	};
}