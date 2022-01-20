#ifndef FRAMEWORK_IMAGETRANSFORM_H_
#define FRAMEWORK_IMAGETRANSFORM_H_

#include "transform.h"

class ImageTransform : public Transform {
 public:
  explicit ImageTransform(const char *path);

  void setImage(const char *path);

 protected:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget = nullptr) override;

 protected:
  QImage image;
};

#endif  // FRAMEWORK_IMAGETRANSFORM_H_
