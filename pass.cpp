#include "pass.h"

ImageBrightener::ImageBrightener(Image inputImage): m_inputImage(inputImage) {
}

bool ImageBrightener::ValidateImage()
{
    if (m_inputImage.columns <= 1024 && m_inputImage.rows <= 1024) {
        return true;
    } else {
        return false;
    }
}

int ImageBrightener::BrightenImage() {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_inputImage.rows; x++) {
        for (int y = 0; y < m_inputImage.columns; y++) {
            if (m_inputImage.pixels[x * m_inputImage.columns + y] > (255 - 25)) {
                ++attenuatedPixelCount;
                // m_inputImage.pixels[x * m_inputImage.rows + 1 + y] = 255;
                m_inputImage.pixels[x * m_inputImage.columns + y] = 255;
            } else {
                // --attenuatedPixelCount;
                m_inputImage.pixels[x * m_inputImage.columns + y] += 25;
                // m_inputImage.pixels[x * m_inputImage.rows + 1 + y] += 25;
            }
        }
    }
    return attenuatedPixelCount;
}

Image ImageBrightener::GetImage() {
    return m_inputImage;
}
