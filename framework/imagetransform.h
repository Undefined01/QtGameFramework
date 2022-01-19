#ifndef IMAGETRANSFORM_H
#define IMAGETRANSFORM_H

#include "transform.h"

class ImageTransform : public Transform {
public:
  ImageTransform(const char *path);

  void setImage(const char *path);

protected:
  virtual QRectF boundingRect() const override;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget = nullptr) override;

protected:
  QImage image;
};

#endif // IMAGETRANSFORM_H
