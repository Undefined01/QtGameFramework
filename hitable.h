#ifndef HITABLE_H
#define HITABLE_H

#include <component.h>

class Hitable : public Component {
public:
  explicit Hitable();

  virtual void beHit();
};

#endif // HITABLE_H
