#include "ddraw.h"
#include <cmath>

ddraw::ddraw(const float radius, const float height)
{
const float h = M_PI / 12;

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
}

void* ddraw::getVertexes()
{
return vertexes.data();
}

QVector<GLuint> ddraw::getIndexes()
{
return indexes;
}

void* ddraw::getVertexColors()
{
return vertexColors.data();
}

void ddraw::draw(const float rotX, const float rotY, const float rotZ,
const float transpX, const float transpY, const float transpZ)
{



glTranslatef(0, -0.4, -3);
//glRotatef(180, 0, 1, 0);
glRotatef(-40, 1, 0, 0);

GLfloat x = 0.0;
GLfloat y = 0.0; //координаты полигонов
GLfloat angle = 0.0; //

GLfloat angle_stepsize = 0.01; //шаг

GLfloat radius=16;
GLfloat height=84; //задаём высоту и радиус, если они слишком большие, то проекция "вылазит" за камеру

GLfloat PI = 3.1415927;

GLubyte R=67;
GLubyte G=109;
GLubyte B=220; //цвет

glColor3ub(R-200,G-50,B-70);
glBegin(GL_QUAD_STRIP); //отрисовываем полигоны типа QUAD STRIP
angle = 0.0;
while( angle < 2*PI ) {
x = radius*cos(angle);
y = radius * sin(angle);
glVertex3f(x, y , height);
glVertex3f(x, y , 0.0);
angle = angle + angle_stepsize;
}
glVertex3f(radius, 0.0, height);
glVertex3f(radius, 0.0, 0.0);
glEnd();

//Draw the circle on top of cylinder
glColor3ub(R-200,G-50,B-70);
glBegin(GL_POLYGON);
angle = 0.0;
while( angle < 2*PI ) {
x = radius*cos(angle);
y = radius * sin(angle);
glVertex3f(x, y , height);
angle = angle + angle_stepsize;
}
glVertex3f(radius, 0.0, height);
glEnd();

//рисуем низ цилиндра
glFrontFace(GL_CW);
glColor3ub(R-200,G-50,B-70);
glBegin(GL_POLYGON);
angle = 0.0;
while( angle < 2*PI ) {
x = radius*cos(angle);
y = radius * sin(angle);
glVertex3f(x, y , 0);
angle = angle + angle_stepsize;
}
glVertex3f(radius, 0.0, 0.0);
glEnd();
glFrontFace(GL_CCW);
}
