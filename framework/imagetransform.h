#ifndef FRAMEWORK_IMAGETRANSFORM_H_
#define FRAMEWORK_IMAGETRANSFORM_H_

#include "transform.h"

class ImageTransform : public Transform {
 public:
  explicit ImageTransform(const char *path);
  void setRect(const QRectF &rect);
  void setPos(const QPointF &pos);

 protected:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget = nullptr) override;

 protected:
  QImage image;
  QRectF imageRect;
};

#endif  // FRAMEWORK_IMAGETRANSFORM_H_
