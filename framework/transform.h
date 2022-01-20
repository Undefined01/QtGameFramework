#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "component.h"
#include <QGraphicsItem>

class Transform : public Component, public QGraphicsItem {
public:
  Transform();
  explicit Transform(const QPointF &pos);

protected:
  virtual QRectF boundingRect() const override;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget = nullptr) override;

protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *ev) override;

protected:
  bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;
};

#endif // TRANSFORM_H
