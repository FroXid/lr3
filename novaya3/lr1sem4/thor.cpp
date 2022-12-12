#include "thor.h"

Thor::Thor(const float radius, const float Radius)
{
    r = radius;
    R = Radius;
    const float h = M_PI / 12;

    //Вычисление вершин стенок конуса и добавление их в индексы
    uint i = 0;
    for(float b = 0; b < 2*M_PI; b += h ) {

        for(float a = 0; a < M_PI_2; a += h) {
            vertexes += (R  + r*cos(b))*cos(a);
            vertexes += (R  + r*cos(b))*sin(a);
            vertexes += r*sin(b);

            vertexColors += sin(a);
            vertexColors += cos(a);
            vertexColors += tan(a);

            indexes += i;
            i++;


            vertexes += (R  + r*cos(b))*cos(a + h);
            vertexes += (R  + r*cos(b))*sin(a + h);
            vertexes += r*sin(b);

            vertexColors += sin(a);
            vertexColors += cos(a);
            vertexColors += tan(a);

            indexes += i;
            i++;

            vertexes += (R  + r*cos(b + h))*cos(a + h);
            vertexes += (R  + r*cos(b + h))*sin(a + h);
            vertexes += r*sin(b + h);

            vertexColors += sin(a);
            vertexColors += cos(a);
            vertexColors += tan(a);

            indexes += i;
            i++;

            vertexes += (R  + r*cos(b + h))*cos(a);
            vertexes += (R  + r*cos(b + h))*sin(a);
            vertexes += r*sin(b + h);

            vertexColors += sin(a);
            vertexColors += cos(a);
            vertexColors += tan(a);

            indexes += i;
            i++;

        }



    }

}

void* Thor::getVertexes()
{
    return vertexes.data();
}

QVector<GLuint> Thor::getIndexes()
{
    return indexes;
}

void* Thor::getVertexColors()
{
    return vertexColors.data();
}

void Thor::draw(const float rotX, const float rotY, const float rotZ,
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
    glDrawElements(GL_QUADS, indexes.size(), GL_UNSIGNED_INT, indexes.data());

    // Рисуем основание конуса
    glFrontFace(GL_CW);
    glVertexPointer(3, GL_FLOAT, 0, vertexesBase.data());
    glColorPointer(3, GL_FLOAT, 0, vertexColorsBase.data());
    glDrawElements(GL_POLYGON, indexesBase.size(), GL_UNSIGNED_INT, indexesBase.data());
    glFrontFace(GL_CCW);
    glPopMatrix();

}
