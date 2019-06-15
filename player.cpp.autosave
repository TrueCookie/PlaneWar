#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem (parent){
    bang = new QMediaPlayer();
    bang->setMedia(QUrl("qrc:/sounds/Gun.mp3"));
    setPixmap(QPixmap(":/sprites/Sprites/Player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    qDebug() << "key is pressed";
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-10, y());
        }
    }else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < scene()->width()){
            setPos(x()+10, y());
        }
    }else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }else if(event->key() == Qt::Key_Space){
        //create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+50, y()+70);
        scene()->addItem(bullet);
        connect(bullet, &Bullet::hit, this, &Player::destroyed);

        if(bang->state() == QMediaPlayer::PlayingState){
            bang->setPosition(0);
        }else if(bang->state() == QMediaPlayer::StoppedState){
            bang->play();
        }
        qDebug() << "Bullet created";
    }
}

void Player::destroyed(){
    emit yeah();
}
