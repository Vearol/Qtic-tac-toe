#include "Strategy.h"
#include <QDebug>

Strategy::Strategy()
{
    //qDebug() << "strategy created " << endl;
}

bool contains(QList<Point*> list, Point* point){
    bool contains = false;
    for (auto &item: list) {
        //qDebug() << item->ToString() << " " << point->ToString();
        if (item->ToString() == point->ToString()) {
            contains = true;
            break;   }
    }
    return contains;
}

Point Strategy::FirstMove(short x, short y)
{
    Point point(x,y);
    //qDebug() << "first Move" << point.ToString() << endl;

    if (contains(_strategy1, &point)){
        qDebug() << "strategy1";
        return Point(1,1);
    }
    if (contains(_strategy2, &point)){
        qDebug() << "strategy2";
        if (x - 1 == 0)
            return Point(x-1, y);
        return Point(x, y+1);
    }
    if (contains(_strategy3, &point)){
        qDebug() << "strategy3";
        short rand = qrand() % 4;
        return *_strategy1[rand];
    }
    return Point(-1,-1);
}

