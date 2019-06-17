#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent){
    setPos(rand()%700,-2*height);

    setPixmap(QPixmap(":/sprites/Sprites/Enemy.png"));
    setTransformOriginPoint(weight, height);
    setRotation(180);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){ 
    setPos(x(), y()+5);
    if(pos().y() > 600){
        emit hurt();
        scene()->removeItem(this);
        delete this;
    }
}
