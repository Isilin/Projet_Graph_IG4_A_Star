#pragma once

#include <vector>
#include <fstream>

namespace vdr
{
	class Bitmap {
	public:
		Bitmap(const char* filename);
		~Bitmap();

		std::vector<unsigned int> getPixel(int i, int j);
		int getHeight() const;
		int getWidth() const;

		void dispPixelData();

	private:
		unsigned char m_bmpFileHeader[14];
		unsigned int m_pixelArrayOffset;
		unsigned char m_bmpInfoHeader[40];

		int m_height;
		int m_width;
		int m_bitsPerPixel;

		int m_rowSize;
		int m_pixelArraySize;

		unsigned char* m_pixelData;
	};
}