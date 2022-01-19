#ifndef SUMMONDUMMY_H
#define SUMMONDUMMY_H

#include <component.h>

class SummonDummy : public Component {
public:
  SummonDummy();

  void onAttach() override;

  void onClick(QGraphicsSceneMouseEvent *ev) override;
};

#endif // SUMMONDUMMY_H
