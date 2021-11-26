#include "BitmapHandler.h"
void BitmapHandler::saveAsBMP(const char* fileName)
{
    FILE* file;
    unsigned long imageSize;
    GLbyte* data = NULL;
    GLint viewPort[4];
    GLenum lastBuffer;
    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;
    bmfh.bfType = 'MB';
    bmfh.bfReserved1 = 0;
    bmfh.bfReserved2 = 0;
    bmfh.bfOffBits = 54;
    glGetIntegerv(GL_VIEWPORT, viewPort);
    imageSize = ((viewPort[2] + ((4 - (viewPort[2] % 4)) % 4)) * viewPort[3] * 3) + 2;
    bmfh.bfSize = imageSize + sizeof(bmfh) + sizeof(bmih);
    data = (GLbyte*)malloc(imageSize);
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    glPixelStorei(GL_PACK_ROW_LENGTH, 0);
    glPixelStorei(GL_PACK_SKIP_ROWS, 0);
    glPixelStorei(GL_PACK_SKIP_PIXELS, 0);
    glPixelStorei(GL_PACK_SWAP_BYTES, 1);
    glGetIntegerv(GL_READ_BUFFER, (GLint*)&lastBuffer);
    glReadBuffer(GL_FRONT);
    glReadPixels(0, 0, viewPort[2], viewPort[3], GL_BGR, GL_UNSIGNED_BYTE, data);
    data[imageSize - 1] = 0;
    data[imageSize - 2] = 0;
    glReadBuffer(lastBuffer);
    fopen_s(&file, fileName, "wb");
    bmih.biSize = 40;
    bmih.biWidth = viewPort[2];
    bmih.biHeight = viewPort[3];
    bmih.biPlanes = 1;
    bmih.biBitCount = 24;
    bmih.biCompression = 0;
    bmih.biSizeImage = imageSize;
    bmih.biXPelsPerMeter = 45089;
    bmih.biYPelsPerMeter = 45089;
    bmih.biClrUsed = 0;
    bmih.biClrImportant = 0;
    fwrite(&bmfh, sizeof(bmfh), 1, file);
    fwrite(&bmih, sizeof(bmih), 1, file);
    fwrite(data, imageSize, 1, file);
    free(data);
    fclose(file);
}

GLuint BitmapHandler::loadTexture(const char* filename, int width, int height) {
    FILE* fp;
    float rowsize, pixelarraysize;
    BITMAPFILEHEADER bitmp;
    BITMAPINFOHEADER bitm;

    fopen_s(&fp, filename, "rb");//Filename is given 
    printf("sizeheader: %d\n", sizeof(bitmp));
    fread(&bitmp, sizeof(bitmp), 1, fp);
    fread(&bitm, sizeof(bitm), 1, fp);

    //printf("Type in hexadecimal: %x\n", bitmp.type);
    //printf("Size in hexadecimal: %x\n", bitmp.size);
    //printf("Reserved1 in hexadecimal: %x\n", bitmp.reserved1);
    //printf("Reserved2 in hexadecimal: %x\n", bitmp.reserved2);
    //printf("Offsetbits in hexadecimal: %x\n", bitmp.offsetbits);

    //printf("Width: %d, Height: %d\n", bitm.width, bitm.height);
    //printf("Bitcount: %d\n", bitm.bitcount);

    rowsize = (width * 3 * 4 + 3) / 4;
    pixelarraysize = rowsize * height;

    printf("Rowsize: %f\n", rowsize);
    printf("pixelarraysize: %f\n", pixelarraysize);

    std::vector<unsigned char> v_data(pixelarraysize);
    fread(v_data.data(), 1, pixelarraysize, fp);
    fclose(fp);


    unsigned int texture;
    glGenTextures(1, &texture);

    //glActiveTexture(GL_TEXTURE);
    //glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, &v_data[0]);

    return texture;
}