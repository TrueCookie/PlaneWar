#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Player : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent=nullptr);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void destroyed();
private:
    QMediaPlayer *bang;
signals:
    void yeah();
};

#endif // MYRECT_H