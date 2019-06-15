#ifndef PLAY_H
#define PLAY_H
#include <QObject>
#include "game.h"

class Play : public QObject{
    Q_OBJECT
private:
    Game* game;
public:
    Play();
public slots:
    void restart();
};

#endif // PLAY_H
