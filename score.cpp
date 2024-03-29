#include "score.h"
#include <QFont>
#include <QKeyEvent>
#include <QDebug>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}

void Score::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_R){
        qDebug() << "Restart is pressed";
        emit restart();
    }
}
