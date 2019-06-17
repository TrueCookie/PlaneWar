#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>

Bullet::Bullet(QGraphicsItem *parent) : QObject() ,QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/sprites/Sprites/Bullet.png"));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);


}

void Bullet::move(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) ==typeid(Enemy)){
            emit hit();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y()-10);
    if(pos().y()+30 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
