#include "pass.h"

ImageBrightener::ImageBrightener(Image& inputImage): m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;
    const int& img_rows = m_inputImage.getRows();
    const int& img_cols = m_inputImage.getCols();

    for (int x = 0; x < img_rows; x++) {
        for (int y = 0; y < img_cols; y++) {
            if (m_inputImage.pixels[x * img_cols + y] > (255 - 25)) {
                ++attenuatedPixelCount;
                // m_inputImage.pixels[x * img_rows + 1 + y] = 255;
                m_inputImage.pixels[x * img_cols + y] = 255;
            } else {
                // --attenuatedPixelCount;
                // m_inputImage.pixels[x * img_cols + y] += 25;
                int pixelIndex = x * img_cols + y;
                m_inputImage.pixels[pixelIndex] += 25;
                // m_inputImage.pixels[x * img_rows + 1 + y] += 25;
            }
        }
    }
    return attenuatedPixelCount;
}

bool ImageBrightener::AddBrighteningImage(Image &imageToAdd, int& attenuatedCount) {
    const int& img_rows = m_inputImage.getRows();
    const int& img_cols = m_inputImage.getCols();

    if (imageToAdd.getRows() != img_rows || imageToAdd.getCols() != img_cols) {
        return false;
    }
    attenuatedCount = 0;
    for (int x = 0; x < img_rows; x++) {
        for (int y = 0; y < img_cols; y++) {
            int pixelIndex = x * img_cols + y;
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

const Image& ImageBrightener::GetResult() {
    return m_inputImage;
}
