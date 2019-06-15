#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent){
    //initialize the score to 3
    health = 3;

    //draw thetext
    setPlainText(QString("Health: ") + QString::number(health)); //Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease(){
    health--;
    if(health == 0){
        emit zero();
    }
    setPlainText(QString("Health: ") + QString::number(health)); //Health: *-1*
}

int Health::getHealth(){
    return health;
}
