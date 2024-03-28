#include "pass.h"
#include "image.h"
#include <iostream>

int main() {
    Image image(512, 512);
	std::cout << "Brightening a 512 x 512 image\n";
    ImageBrightener brightener(image);
    int attenuatedCount = brightener.BrightenWholeImage();
    std::cout << "Attenuated " << attenuatedCount << " pixels\n";
    
    const Image& returnedImage = brightener.GetResult();
    std::cout << "Rows: " << image.getRows() << std::endl;
    std::cout << "Columns: " << image.getCols() << std::endl;

    if (&image == &returnedImage) {
        std::cout << "The Image objects are same, no copy made" << std::endl;
    }
    else {
        std::cout << "The Image objects are different, memory wasted!!" << std::endl;
    }
}
