#include "cone.h"

Cone::Cone(const float radius, const float height)
{
    const float h = M_PI / 12;

    // Вершина конуса
    vertexes += 0.0f;
    vertexes += 0.0f;
    vertexes += height;

    //Вычисление вершин стенок конуса и добавление их в индексы
    uint i = 0;
    for(float a=0; a< 2*M_PI; a += h) {
        vertexes += radius*cos(a);
        vertexes += radius*sin(a);
        vertexes += 0.0f;
        vertexColors += sin(a);
        vertexColors += cos(a);
        vertexColors += tan(a);
        indexes += i++;
    }

    // Добавляем в индексы последнюю вершину
    indexes += 1;
}

void* Cone::getVertexes()
{
    return vertexes.data();
}

QVector<GLuint> Cone::getIndexes()
{
    return indexes;
}

void* Cone::getVertexColors()
{
    return vertexColors.data();
}

void Cone::draw(const float rotX, const float rotY, const float rotZ,
                const float transpX, const float transpY, const float transpZ)
{
    glPushMatrix();
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(transpX, transpY, transpZ);

    // Рисуем стенки конуса
    glVertexPointer(3, GL_FLOAT, 0, vertexes.data());
    glColorPointer(3, GL_FLOAT, 0, vertexColors.data());
    glDrawElements(GL_TRIANGLE_FAN, indexes.size(), GL_UNSIGNED_INT, indexes.data());

    // Рисуем основание конуса
    glFrontFace(GL_CW);
    glDrawElements(GL_POLYGON, indexes.size() - 1, GL_UNSIGNED_INT, indexes.data() + 1);
    glFrontFace(GL_CCW);
    glPopMatrix();

}
