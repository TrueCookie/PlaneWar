#include "health.h"
#include <QFont>
#include <QKeyEvent>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease(){
    health--;
    if(health == 0){
        emit zero();
    }
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
