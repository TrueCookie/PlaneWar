#include "game.h"
#include "player.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "background.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QWidget>
#include <QBrush>
#include <QImage>


Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //setBackgroundBrush(QBrush(QImage(":/new/prefix/Sprites/space.png")));
    Background *background = new Background();
    scene->addItem(background);

    //add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);
    view->setBackgroundBrush(QBrush(QImage(":/new/prefix/Sprites/space.png")));
    view->show();
    //create an item to put into the scene
    player = new Player();
    //setPixmap(QPixmap(":/sprites/Sprites/Player.png"));

    player->setPos(view->width()/2, view->height()-185);

    //add the item to the scene
    scene->addItem(player);

    //make rect focusible
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create the score/health
    score = new Score();
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(score);
    scene->addItem(health);

    //spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, this, &Game::spawn);
    timer->start(2000);

    //play background music
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/BGMusic.mp3"));
    music->play();
    
    connect(player, &Player::yeah, score, &Score::increase);
    connect(health, &Health::zero, this, &Game::over);
}

void Game::spawn(){
    Enemy *enemy = new Enemy();
    connect(enemy, &Enemy::hurt, health, &Health::decrease);
    scene->addItem(enemy);
}

void Game::over(){
    qDebug() << "GAMEOVER";
    QGraphicsTextItem* text = new QGraphicsTextItem("GAME OVER");
    text->setScale(10.0);
    text->setPos(512,scene->height()/3);
    scene->addItem(text);
    score->setPos(scene->width()/3,text->pos().y()+512);
    score->setScale(4.0);
    delete player;
}
