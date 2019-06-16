#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem{
    Q_OBJECT
public:
    Score(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    void increase();
    int getScore();   
private:
    int score;
signals:
    void restart();
};

#endif // SCORE_H
