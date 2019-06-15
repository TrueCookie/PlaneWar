#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    const int weight = 184;
    const int height = 185;
public:
    Enemy(QGraphicsItem *parent = nullptr);
public slots:
    void move();
signals:
    void hurt();
};

#endif // ENEMY_H
