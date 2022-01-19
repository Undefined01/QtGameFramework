#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QList>
#include <QMap>

class GameObject;

class GameScene final : public QGraphicsScene {
  Q_OBJECT
public:
  GameScene();

  // Game object management API
public:
  void attachGameObject(GameObject *gameObject);
  void detachGameObject(GameObject *gameObject);
  GameObject *getGameObject(const char *name);

private:
  QTimer *updateTimer = nullptr;
  QList<GameObject *> gameObjects;
  QList<GameObject *> gameObjectsToAttach;
  QList<GameObject *> gameObjectsToDetach;
  QList<GameObject *> gameObjectsAttachedOnLastUpdate;
  void onUpdate();

  // Keyboard input API
  // Require clearing keyDownArray and keyUpArray after update()
public:
  bool getKey(Qt::Key key) { return keyArray[key]; }
  bool getKeyDown(Qt::Key key) { return keyDownArray[key]; }
  bool getKeyUp(Qt::Key key) { return keyUpArray[key]; }

private:
  QMap<int, bool> keyArray;
  QMap<int, bool> keyDownArray, keyUpArray;
  void keyPressEvent(QKeyEvent *ev) override;
  void keyReleaseEvent(QKeyEvent *ev) override;
  void focusOutEvent(QFocusEvent *ev) override;
};

#endif // GAMESCENE_H
