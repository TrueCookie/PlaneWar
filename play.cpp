#include <QApplication>
#include <QTextCodec>
#include "play.h"
#include "game.h"
#include "play.h"

Play::Play(){
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    game = new Game();
    connect(game, &Game::restart, this, &Play::restart);
}

void Play::restart(){
    game = new Game();
}
