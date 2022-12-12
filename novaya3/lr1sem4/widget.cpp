#include "widget.h"
#include "ui_widget.h"
#include "ddraw.h"
#include "cone.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::Widget), xRot(0), yRot(0), zRot(0)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);

    coneVertical = new Cone(34.0f, 80.0f);
    ddrawHorizontal = new ddraw(25.0f, 72.0f);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glLoadIdentity();
    glRotated(xRot, 1.0, 0.0, 0.0);
    glRotated(yRot, 0.0, 1.0, 0.0);
    glRotated(zRot, 0.0, 0.0, 1.0);
    glTranslatef(xTranslation, yTranslation, 0);
    glScalef(scale, scale, scale);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    coneVertical->draw(-90, 0, 0);

    ddrawHorizontal->draw(40, 0, 0,  0.0f, 20.0f, -60.0f);


    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void Widget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-80.0, 80.0, -80.0, 80.0, -80.0, 80.0);
    glMatrixMode(GL_MODELVIEW);
}

void Widget::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_W) {
        yTranslation += 0.5f;
    } else if ( event->key() == Qt::Key_S) {
        yTranslation -= 0.5f;
    } else if ( event->key() == Qt::Key_A) {
        xTranslation -= 0.5f;
    } else if ( event->key() == Qt::Key_D) {
        xTranslation += 0.5f;
    }
    update();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->pos().x() - lastPos.x();
    int dy = event->pos().y() - lastPos.y();
    if (event->buttons() & Qt::LeftButton) {
        xRot += dy;
        yRot += dx;
    } else if (event->buttons() & Qt::RightButton) {
        xRot += dy;
        zRot += dx;
    }
    lastPos = event->pos();
    update();
}

void Widget::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 8;;

    if (!numDegrees.isNull()) {
        QPoint numSteps = numDegrees / 15;
        if ((scale + (float) numSteps.y() / 25.0f) >= 0) {
            scale += ((float) numSteps.y() / 25.0f);
        }
    }

    event->accept();
    update();
}
