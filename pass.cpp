#include "pass.h"

ImageBrightener::ImageBrightener(Image& inputImage): m_inputImage(inputImage) {
}

bool ImageBrightener::ValidateImage()
{
    if (m_inputImage.columns <= 1024 && m_inputImage.rows <= 1024) {
        return true;
    } else {
        return false;
    }
}

int ImageBrightener::BrightenWholeImage() {
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
                // m_inputImage.pixels[x * m_inputImage.columns + y] += 25;
                int pixelIndex = x * m_inputImage.columns + y;
                m_inputImage.pixels[pixelIndex] += 25;
                // m_inputImage.pixels[x * m_inputImage.rows + 1 + y] += 25;
            }
        }
    }
    return attenuatedPixelCount;
}

bool ImageBrightener::AddBrighteningImage(Image &imageToAdd, int& attenuatedCount) {
    if (imageToAdd.rows != m_inputImage.rows || imageToAdd.columns != m_inputImage.columns) {
        return false;
    }
    attenuatedCount = 0;
    for (int x = 0; x < m_inputImage.rows; x++) {
        for (int y = 0; y < m_inputImage.columns; y++) {
            int pixelIndex = x * m_inputImage.columns + y;
            if (int(m_inputImage.pixels[pixelIndex]) + imageToAdd.pixels[pixelIndex] > 255) {
                ++attenuatedCount;
                m_inputImage.pixels[pixelIndex] = 255;
            } else {
                imageToAdd.pixels[pixelIndex] += m_inputImage.pixels[pixelIndex];
            }
        }
    }
    return true;
}

Image ImageBrightener::GetImage() {
    return m_inputImage;
}
