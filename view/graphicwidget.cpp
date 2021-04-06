#include "graphicwidget.h"
#include <QGraphicsView>

GraphicWidget::GraphicWidget(QWidget *parent) : QGraphicsView(parent) {

}

void GraphicWidget::mousePressEvent(QMouseEvent *event) {
    emit mouseClicked(event->x(), event->y());
}

