#include "pass.h"
#include <iostream>

int main() {
    Image image;
    image.rows = 512;
    image.columns = 512;
    ImageBrightener brightener(image);
    int attenuatedCount = brightener.BrightenImage();
    std::cout << "Attenuated " << attenuatedCount << " pixels\n";
}
