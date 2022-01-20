#include "imagetransform.h"

#include <QPainter>
#include <utility>

ImageTransform::ImageTransform(const char *path) {}

void ImageTransform::setImage(const char *path) {
  if (path != nullptr)
    this->image.load(path);
  else
    this->image = std::move(QImage{});
}

QRectF ImageTransform::boundingRect() const { return this->image.rect(); }
void ImageTransform::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget) {
  if (this->image.isNull()) return;
  painter->drawImage(this->boundingRect(), this->image);
}
