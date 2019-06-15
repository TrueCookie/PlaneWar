#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "player.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView{
public:
    Game(QWidget *parent = nullptr);
    void spawn();
    void over();
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;
};

#endif // GAME_H
