#include <cstdint>
#include "image.h"

class ImageBrightener {
    private:
        Image& m_inputImage;
    public:
        ImageBrightener(Image& inputImage);
        int BrightenWholeImage();
        bool AddBrighteningImage(Image& imageToAdd, int& attenuatedCount);
        const Image& GetResult();
};
