#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>

//extern Game *game; //there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent) : QObject() ,QGraphicsPixmapItem(parent){
    //drew the rect
    setPixmap(QPixmap(":/sprites/Sprites/Bullet.png"));

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);


}

void Bullet::move(){
    //if bullet collides with enemy
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) ==typeid(Enemy)){
            //game->score->increase();
            emit hit();
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet up
    setPos(x(), y()-10);
    if(pos().y()+30 < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}
