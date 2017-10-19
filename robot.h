#ifndef ROBOT_H
#define ROBOT_H

#include <QPoint>
#include <QString>
#include <QTime>


class Robot
{
public:
    Robot(int x, int y);
    int x();
    int y();
    QString color();

    void nextStep();
    void addStep(QPoint p);
private:
    QPoint pos;
    QList<QPoint> path;
    QString source;
    QString s_color;
    bool calculatePath(QVector<QVector<int> > *field,  int bx, int by);

};

#endif // ROBOT_H
