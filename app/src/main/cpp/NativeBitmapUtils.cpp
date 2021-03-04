//
// Created by Jesson on 3/3/21.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "NativeBitmapUtils.h"

#pragma pack(1) //设定字节对齐方式

jni::NativeBitmapUtils::NativeBitmapUtils(const char *pFilePath) {
    FILE *pFile = fopen(pFilePath, "rb");
    if (pFile == NULL)
    {
        memset(&m_bitmpFileHeader, 0x00, sizeof(BITMAPFILEHEADER));
        memset(&m_bitmapInfoHeader, 0x00, sizeof(BITMAPINFOHEADER));
        m_ImageSize = 0;
        m_ImageData = NULL;
    }
    else
    {
        fread(&m_bitmpFileHeader, sizeof(BITMAPFILEHEADER), 1, pFile);

        fread(&m_bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, pFile);

        int nPos = ftell(pFile);
        fseek(pFile, 0L, SEEK_END);
        m_ImageSize = ftell(pFile) - nPos;
        m_ImageData = new byte[m_ImageSize];
        memset(m_ImageData, 0x00, m_ImageSize + 1);
        fseek(pFile, -m_ImageSize, SEEK_END);
        fread(m_ImageData, m_ImageSize, 1, pFile);

        m_bitmapInfoHeader.biWidth = abs(m_bitmapInfoHeader.biWidth);
        m_bitmapInfoHeader.biHeight = abs(m_bitmapInfoHeader.biHeight);

        fclose(pFile);
    }
}

jni::NativeBitmapUtils::~NativeBitmapUtils() {
    if (m_ImageData)
    {
        delete [] m_ImageData;
        m_ImageData = NULL;
    }
}

WORD jni::NativeBitmapUtils::GetPixelFormatSize() const {
    return m_bitmapInfoHeader.biBitCount;
}

int jni::NativeBitmapUtils::GetWidth() const{
    return m_bitmapInfoHeader.biWidth;
}

int jni::NativeBitmapUtils::GetHeight() const{
    return m_bitmapInfoHeader.biHeight;
}

int jni::NativeBitmapUtils::GetImageSize() const{
    return m_ImageSize;
}

BITMAPFILEHEADER jni::NativeBitmapUtils::GetFileHeader() const{
    return m_bitmpFileHeader;
}

BITMAPINFOHEADER jni::NativeBitmapUtils::GetInfoHeader() const{
    return m_bitmapInfoHeader;
}

void jni::NativeBitmapUtils::GetImageData(byte *pszData) const{
    memcpy(pszData, m_ImageData, m_ImageSize);
}
