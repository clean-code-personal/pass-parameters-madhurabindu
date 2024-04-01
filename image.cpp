#include "image.h"
#include <stdexcept>

Image::Image(const int& rows, const int& cols) {
	if (rows < 0 || cols < 0)
		throw std::invalid_argument("Image must have rows and cols");

	if (rows > MAX_IMAGE_SIZE || cols > MAX_IMAGE_SIZE)
		throw std::invalid_argument("Requested Image size not supported");

	size_t pixelsSize = static_cast<size_t>(rows) * static_cast<size_t>(cols);

	if (pixelsSize > SIZE_MAX)
		throw std::overflow_error("Image size exceeds maximum supported size");

	m_rows = rows;
	m_cols = cols;
	pixels = new uint8_t[pixelsSize];
}

Image::~Image() {
	delete[] pixels;
}
