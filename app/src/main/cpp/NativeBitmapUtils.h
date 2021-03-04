//
// Created by Jesson on 3/3/21.
//

#ifndef JNI_HELPER_NATIVEBITMAPUTILS_H
#define JNI_HELPER_NATIVEBITMAPUTILS_H

#include <jni.h>
#include <android/bitmap.h>
typedef int LONG;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned char byte;

typedef struct tagBITMAPFILEHEADER {
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

namespace jni {
    class NativeBitmapUtils {
    private:
        BITMAPFILEHEADER m_bitmpFileHeader{};
        BITMAPINFOHEADER m_bitmapInfoHeader{};
        int m_ImageSize;
        byte *m_ImageData = NULL;

    public:
        NativeBitmapUtils(const char* pFilePath);
        ~NativeBitmapUtils();

        WORD GetPixelFormatSize() const;
        int GetWidth() const;
        int GetHeight() const;
        int GetImageSize() const;
        void GetImageData(byte* pszData) const;

        BITMAPFILEHEADER GetFileHeader() const;
        BITMAPINFOHEADER GetInfoHeader() const;
    };
}


#endif //JNI_HELPER_NATIVEBITMAPUTILS_H
