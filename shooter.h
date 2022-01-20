#ifndef SHOOTER_H
#define SHOOTER_H

#include "component.h"

class Transform;

class Shooter : public Component {
public:
  explicit Shooter();

  void onAttach() override;
  void onUpdate(float deltaTime) override;

protected:
  Transform *transform = nullptr;

  const float interval = .5;
  float cooldown = interval;
};

#endif // SHOOTER_H
