#include "transform.h"

#include "gameobject.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>

Transform::Transform() {}
Transform::Transform(const QPointF &pos) { this->setPos(pos); }

void Transform::mousePressEvent(QGraphicsSceneMouseEvent *ev) {
  qDebug("pressed");
  QGraphicsItem::mousePressEvent(ev);
  this->gameObject->onClick(ev);
}

QRectF Transform::boundingRect() const { return QRectF(); }

void Transform::paint([[maybe_unused]] QPainter *painter,
                      [[maybe_unused]] const QStyleOptionGraphicsItem *option,
                      [[maybe_unused]] QWidget *widget) {}
