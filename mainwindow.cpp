#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <gameobject.h>
#include <transform.h>

#include <shooter.h>
#include <summondummy.h>

void loadScene(GameScene *gameScene) {
  auto shooter = new GameObject();
  shooter->addComponent(new Transform(QPointF(100, 100)));
  shooter->addComponent(new Shooter);
  gameScene->attachGameObject(shooter);

  auto summonDummyBtn = new GameObject();
  summonDummyBtn->addComponent(new Transform);
  summonDummyBtn->addComponent(new SummonDummy);
  gameScene->attachGameObject(summonDummyBtn);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  gameScene = new GameScene();
  gameScene->setParent(this);
  auto view = new QGraphicsView(gameScene, this);
  view->resize(this->size());
  view->setSceneRect(0, 0, 100, 100);

  loadScene(gameScene);
}

MainWindow::~MainWindow() { delete ui; }
