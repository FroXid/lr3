#ifndef THOR_H
#define THOR_H

#include <QOpenGLWidget>

class Thor
{
public:
    Thor(const float radius = 1.0f, const float height = 3.0f);
    void*  getVertexes();
    QVector<GLuint> getIndexes();
    void* getVertexColors();
    void draw(const float rotX = 0.0f, const float rotY = 0.0f, const float rotZ = 0.0f,
              const float transpX = 0.0f, const float transpY = 0.0f, const float transpZ = 0.0f);
private:
    QVector<GLfloat> vertexes;
    QVector<GLuint> indexes;
    QVector<GLfloat> vertexColors;

    QVector<GLfloat> vertexesBase;
    QVector<GLuint> indexesBase;
    QVector<GLfloat> vertexColorsBase;

    float R = 115.0f;
    float r = 1.0f;


};

#endif // THOR_H
