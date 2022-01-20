#include "imagetransform.h"

#include <QPainter>
#include <utility>

ImageTransform::ImageTransform(const char *path) {
  if (path != nullptr)
    this->image.load(path);
  else
    this->image = std::move(QImage{});
  imageRect = this->image.rect();
}

void ImageTransform::setRect(const QRectF &rect) {
  imageRect = rect;
}

void ImageTransform::setPos(const QPointF &pos) {
   this->setPos(pos);
}

QRectF ImageTransform::boundingRect() const { return QRectF(0, 0, 40, 40); return this->image.rect(); }

void ImageTransform::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget) {
  if (this->image.isNull()) return;
  painter->drawImage(imageRect, this->image);
}
