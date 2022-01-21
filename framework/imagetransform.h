#ifndef FRAMEWORK_IMAGETRANSFORM_H_
#define FRAMEWORK_IMAGETRANSFORM_H_

#include "transform.h"

class ImageTransform : public Transform {
 public:
  explicit ImageTransform();
  explicit ImageTransform(QPointF pos, const char *path);

  const QImage &getImage();
  bool setImage(const char *path);

  void setOffset(QPointF offset);
  void setAlignment(Qt::Alignment alignment);

 protected:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget = nullptr) override;

 protected:
  QImage image;
  QPointF offset;
  Qt::Alignment alignment;
  QRectF imageRect;

  void updateImageRect();
};

#endif  // FRAMEWORK_IMAGETRANSFORM_H_
