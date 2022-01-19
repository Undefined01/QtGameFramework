#ifndef AMMO_H
#define AMMO_H

#include <component.h>
#include <gameobject.h>
#include <transform.h>

class Ammo : public Component {
public:
  explicit Ammo(QPointF velocity);

  void onAttach() override;
  void onUpdate(float deltaTime) override;

protected:
  Transform *transform;
  QGraphicsItem *collisionItem;

  float timeToLive = 1;
  QPointF velocity;
};

#endif // AMMO_H
