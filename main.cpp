#include <QApplication>
#include <QTextCodec>
#include "game.h"

static Game* game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    //QTextCodec::setCodecForCStrings(codec);

    game = new Game();
    //game->show();

    return a.exec();
}
