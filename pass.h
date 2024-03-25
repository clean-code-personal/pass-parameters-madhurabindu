#include <cstdint>

struct Image {
    int rows;
    int columns;
    uint8_t pixels[1024*1024]; // max 1k x 1k image
};

class ImageBrightener {
    private:
        Image m_inputImage;
    public:
        ImageBrightener(Image& inputImage);
        bool ValidateImage();
        int BrightenWholeImage();
        bool AddBrighteningImage(Image& imageToAdd, int& attenuatedCount);
        Image GetImage();
};
