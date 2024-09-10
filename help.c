#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void apply_box_blur(uint8_t *pixels, int width, int height, int row_stride) {
    int kernel_size = 3;
    int offset = kernel_size / 2;

    uint8_t *temp = (uint8_t *)malloc(row_stride * height);
    if (!temp) {
        fprintf(stderr, "Failed to allocate memory for temp buffer.\n");
        exit(1);
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int r = 0, g = 0, b = 0;
            int count = 0;

            for (int ky = -offset; ky <= offset; ++ky) {
                for (int kx = -offset; kx <= offset; ++kx) {
                    int px = x + kx;
                    int py = y + ky;

                    if (px >= 0 && px < width && py >= 0 && py < height) {
                        int index = (py * row_stride) + (px * 3);
                        b += pixels[index];
                        g += pixels[index + 1];
                        r += pixels[index + 2];
                        count++;
                    }
                }
            }

            int idx = (y * row_stride) + (x * 3);
            temp[idx] = b / count;
            temp[idx + 1] = g / count;
            temp[idx + 2] = r / count;
        }
    }

    for (int i = 0; i < row_stride * height; ++i) {
        pixels[i] = temp[i];
    }

    free(temp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (!in) {
        perror("Failed to open input file");
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, in);
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, in);

    if (fileHeader.bfType != 0x4D42) { // 'BM'
        fprintf(stderr, "Unsupported BMP file format.\n");
        fclose(in);
        return 1;
    }

    int width = infoHeader.biWidth;
    int height = abs(infoHeader.biHeight);
    int row_stride = ((width * 24 + 31) / 32) * 4; // Row size in bytes

    uint8_t *pixels = (uint8_t *)malloc(row_stride * height);
    if (!pixels) {
        fprintf(stderr, "Failed to allocate memory for image data.\n");
        fclose(in);
        return 1;
    }

    fseek(in, fileHeader.bfOffBits, SEEK_SET);
    fread(pixels, 1, row_stride * height, in);
    fclose(in);

    apply_box_blur(pixels, width, height, row_stride);

    FILE *out = fopen(argv[2], "wb");
    if (!out) {
        perror("Failed to open output file");
        free(pixels);
        return 1;
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, out);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, out);
    fwrite(pixels, 1, row_stride * height, out);
    fclose(out);
    free(pixels);

    return 0;
}
