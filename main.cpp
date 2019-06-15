#include <QApplication>
#include <QTextCodec>
#include "play.h"
#include "game.h"



int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    Play* play = new Play();

    return a.exec();
}
