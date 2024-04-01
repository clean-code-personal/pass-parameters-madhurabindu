#ifndef IMAGE_H 
#define IMAGE_H

#include <cstdint>

struct Image {
private:
    static const int MAX_IMAGE_SIZE = 1024;
    int m_rows;
    int m_cols;
public:
    uint8_t* pixels;
    Image(const int& rows, const int& cols);
    ~Image();
    int getRows() const { return m_rows; }
    int getCols() const { return m_cols; }
};

#endif 