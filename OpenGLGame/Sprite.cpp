#include "Sprite.h"

Sprite::Sprite(Texture2D* texture)
{
    this->texture = texture;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

void Sprite::draw(float x, float y)
{
    
    

    float sizeX, sizeY;
    sizeX = getWidth();
    sizeY = getHeight();

    GLfloat vertices[] = {
        x, y, 0, 1,
        x, y + sizeY, 0, 0,
        x + sizeX, y, 1, 1,
        x, y + sizeY, 0, 0,
        x + sizeX, y + sizeY, 1, 0,
        x + sizeX, y, 1, 1,
    };



    glActiveTexture(GL_TEXTURE0);
    this->texture->bind();

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);

    this->texture->unbind();
}

Texture2D* Sprite::getTexture()
{
    return this->texture;
}

void Sprite::setTexture(Texture2D* texture)
{
    this->texture = texture;
}

int Sprite::getWidth()
{
    return this->texture->getWidth();
}

int Sprite::getHeight()
{
    return this->texture->getHeight();
}
