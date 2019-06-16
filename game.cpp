#include "game.h"
#include "player.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QWidget>
#include <QBrush>
#include <QImage>
#include <QKeyEvent>


Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,screenWidth,screenHeight);

    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    view->setBackgroundBrush(QBrush(QImage(":/new/prefix/Sprites/space.png")));
    view->show();

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/BGMusic.mp3"));
    music->play();

    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, this, &Game::spawn);
    timer->start(2000);
    restart();
}

void Game::spawn(){
    Enemy *enemy = new Enemy();
    connect(enemy, &Enemy::hurt, health, &Health::decrease);
    scene->addItem(enemy);
}

void Game::over(){
    //scene->clear();
    scene->removeItem(health);
    //scene->removeItem(player);
    text = new QGraphicsTextItem("GAME OVER");
    text->setScale(10.0);
    text->setPos(64,scene->height()/3);
    scene->addItem(text);
    score->setPos(scene->width()/3,text->pos().y()+128);
    score->setScale(4.0);
}

void Game::restart(){
    qDebug() << "restarted";
    scene->clear();

    player = new Player();
    player->setPos(view->width()/2, view->height()-185);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    score = new Score();
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(score);
    scene->addItem(health);

    connect(player, &Player::restart, this, &Game::restart);
    connect(player, &Player::yeah, score, &Score::increase);
    connect(health, &Health::zero, this, &Game::over);
}
