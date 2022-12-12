#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QtMath>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <Thor.h>
#include "Cone.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;

private:
    Ui::Widget *ui;

    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

    QPoint lastPos;
    int xRot = 0.0f, yRot = 0.0f, zRot = 0.0f;
    GLfloat xTranslation = 0.0f, yTranslation = 0.0f, zTranslation = 0.0f;
    GLfloat scale = 1.0f;

    Thor* thor;

};
#endif // WIDGET_H
