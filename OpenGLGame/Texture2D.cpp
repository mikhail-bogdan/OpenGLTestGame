#include "Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture2D::Texture2D(int width, int height)
{
    this->width = width;
    this->height = height;

    this->data = new uint*[this->height];
    for (int i = 0; i < this->height; i++)
        this->data[i] = new uint[this->width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            this->data[i][j] = PACK_PIXEL(255, 255, 255, 255);


    uint* data = new uint[width * height];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            data[i * width + j] = this->data[i][j];

    glGenTextures(1, &this->textureID);
    this->bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_INT_8_8_8_8, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    this->unbind();
    delete[] data;
}

Texture2D::Texture2D(std::string path)
{
    int nChannels;
    byte* data = stbi_load(path.c_str(), &this->width, &this->height, &nChannels, 0);

    this->data = new uint * [this->height];
    for (int i = 0; i < this->height; i++)
        this->data[i] = new uint[this->width];

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            this->data[i][j] = PACK_PIXEL(
                data[(i * width + j) * 3 + 2],
                data[(i * width + j) * 3 + 1],
                data[(i * width + j) * 3],
                255);
        }
    }

    glGenTextures(1, &this->textureID);
    this->bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    this->unbind();
    delete[] data;
}

int Texture2D::getWidth()
{
    return this->width;
}

int Texture2D::getHeight()
{
    return this->height;
}

void Texture2D::resize(int width, int height)
{
    byte* tmp_data = new byte[3 * width * height];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i >= this->height || j >= this->width)
            {
                tmp_data[(i * width + j) * 3] = 0;
                tmp_data[(i * width + j) * 3 + 1] = 0;
                tmp_data[(i * width + j) * 3 + 2] = 0;
            }
            else
            {
                //tmp_data[(i * width + j) * 3] = this->data[(i * this->width + j) * 3];
                //tmp_data[(i * width + j) * 3 + 1] = this->data[(i * this->width + j) * 3 + 1];
                //tmp_data[(i * width + j) * 3 + 2] = this->data[(i * this->width + j) * 3 + 2];
            }
        }
    }
    delete[] this->data;
    //this->data = tmp_data;
    //this->width = width;
    this->height = height;
    this->bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, this->data);
    glGenerateMipmap(GL_TEXTURE_2D);
    this->unbind();
}

int Texture2D::getPixel(int x, int y)
{
    return this->data[y][x];
}

void Texture2D::setPixel(int x, int y, byte grayscale)
{
    int r = grayscale;
    int g = grayscale;
    int b = grayscale;
    int a = 255;
    this->data[y][x] = PACK_PIXEL(r, g, b, a);
    this->isDirty = true;
}

void Texture2D::setPixel(int x, int y, byte grayscale, byte alpha)
{
    int r = grayscale;
    int g = grayscale;
    int b = grayscale;
    this->data[y][x] = PACK_PIXEL(r, g, b, alpha);
    this->isDirty = true;
}

void Texture2D::setPixel(int x, int y, byte r, byte g, byte b)
{
    int a = 255;
    this->data[y][x] = PACK_PIXEL(r, g, b, a);
    this->isDirty = true;
}

void Texture2D::setPixel(int x, int y, byte r, byte g, byte b, byte a)
{
    this->data[y][x] = PACK_PIXEL(r, g, b, a);
    this->isDirty = true;
}

void Texture2D::bind()
{
    if (this->isDirty) this->refreshTexture();
    glBindTexture(GL_TEXTURE_2D, this->textureID); // скорее всего нужно переделать
}

void Texture2D::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &this->textureID);
    for (int i = 0; i < this->height; i++)
        delete[] this->data[i];
    delete[] this->data;
}

void Texture2D::refreshTexture()
{
    this->isDirty = false;
    uint* data = new uint[this->width * this->height];
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            data[i * this->width + j] = this->getPixel(j, i);
        }
    }

    this->bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    this->unbind();
}