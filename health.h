#ifndef HEALTH_H
#define HEALTH_H

#include "hitable.h"

class Health : public Hitable {
public:
  Health(int health);

  void beHit() override;

protected:
  int health;
};

#endif // HEALTH_H
