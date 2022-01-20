#include "ammo.h"

#include "hitable.h"

#include <QBrush>
#include <QGraphicsEllipseItem>

Ammo::Ammo(QPointF velocity) : Component(), velocity(velocity) {}

void Ammo::onAttach() {
  this->transform = this->gameObject->getComponent<Transform>();
  Q_ASSERT(this->transform != nullptr);
  auto circle = new QGraphicsEllipseItem(this->transform);
  circle->setRect(QRectF(-10, -10, 20, 20));
  circle->setBrush(QBrush(Qt::black));
  this->collisionItem = circle;
}

void Ammo::onUpdate(float deltaTime) {
  timeToLive -= deltaTime;
  if (timeToLive < 0) {
    destory(this->gameObject);
  }

  this->transform->setPos(this->transform->pos() + velocity * deltaTime);
  for (auto item : this->collisionItem->collidingItems()) {
    while (item->parentItem() != nullptr)
      item = item->parentItem();
    auto transform = dynamic_cast<Transform *>(item);
    if (transform == nullptr)
      continue;
    auto gameObject = transform->getParentGameObject();
    auto hitable = gameObject->getComponent<Hitable>();
    if (hitable == nullptr)
      continue;
    hitable->beHit();
    destory(this->gameObject);
    break;
  }
}
