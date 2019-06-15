#include "background.h"

Background::Background(QGraphicsItem *parent) : QGraphicsPixmapItem (parent){
    setPixmap(QPixmap(":/new/prefix/Sprites/space.png"));
}
