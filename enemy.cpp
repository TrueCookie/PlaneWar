#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>

//extern Game* game;

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem (parent){
    //set random position
    setPos(rand()%700,-284);

    //drew the enemy
    setPixmap(QPixmap(":/sprites/Sprites/Enemy.png"));
    setTransformOriginPoint(184, 185);
    setRotation(180);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    //move enemy down
    setPos(x(), y()+5);

    //delete the enemy
    if(pos().y() > 600){
        //decrease the health
        emit hurt();
        //game->health->decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy deleted";
    }
}

