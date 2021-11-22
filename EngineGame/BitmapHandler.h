#pragma once
//
//struct BMPImage* loadBMP(char* file) {
//    FILE* fp = fopen(file, "r");
//    if (fp == NULL) {
//        fprintf(stderr, "ERROR: could not read file\n");
//        return NULL;
//    }
//
//    fseek(fp, 0, SEEK_END);
//    long fsize = ftell(fp); // get filesize then go back to the beginning of the file
//    rewind(fp);
//    unsigned char* buffer = (unsigned char*)malloc(fsize * sizeof(unsigned char)); // allocate memory on heap
//    fread(buffer, 1, fsize, fp); // read into memory
//    fclose(fp);
//
//    // lets load the data into a bitmap struct
//    struct BMPImage* image = (struct BMPImage*)malloc(sizeof(struct BMPImage));
//
//    // load image
//    if (!readBMPImage(image, buffer)) {
//        // if it fails cleanup memory then return
//        free(image);
//        free(buffer);
//        return NULL;
//    }
//
//    printHeaderInfo(image);
//
//    // should not need buffer after we loadin the memory
//    free(buffer);
//
//    return image;
//}
//
//class BitmapHandler {
//    void unloadBMP(struct BMPImage* bmp) {
//        free(bmp);
//    }
//};