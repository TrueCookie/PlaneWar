#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include <QGraphicsTextItem>

class Health : /*public QObject, */public QGraphicsTextItem{
    Q_OBJECT
public:
    Health(QGraphicsItem *parent = nullptr);
    void decrease();
    int getHealth();
private:
    int health = 0;
signals:
    void zero();
};

#endif // HEALTH_H
