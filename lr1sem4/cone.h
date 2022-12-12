#ifndef CONE_H
#define CONE_H

#include <QOpenGLWidget>

class Cone
{
public:
    Cone(const float radius = 1.0f, const float height = 3.0f);
    void*  getVertexes();
    QVector<GLuint> getIndexes();
    void* getVertexColors();
    void draw(const float rotX = 0.0f, const float rotY = 0.0f, const float rotZ = 0.0f,
              const float transpX = 0.0f, const float transpY = 0.0f, const float transpZ = 0.0f);
private:
    QVector<GLfloat> vertexes;
    QVector<GLuint> indexes;
    QVector<GLfloat> vertexColors;
};

#endif // CONE_H
