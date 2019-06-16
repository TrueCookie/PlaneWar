#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "player.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView{
    Q_OBJECT
private:
    const int screenWidth = 800;
    const int screenHeight = 600;
    QGraphicsTextItem* text;
public:
    Game(QWidget *parent = nullptr);
    QGraphicsView *view;
    QTimer* timer;
    QMediaPlayer *music;

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;
public slots:
    void restart();
    void spawn();
    void over();
//signals:
    //void restart();
};

#endif // GAME_H
