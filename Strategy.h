#ifndef STRATEGY_H
#define STRATEGY_H

#include <QList>
#include <MoveService.h>

class Strategy
{
private:
    QList<Point*> _strategy1 = QList<Point*>() << new Point(0,0) << new Point(0,2)
                                               << new Point(2,0) << new Point(2,2);
    QList<Point*> _strategy2 = QList<Point*>() << new Point(0,1) << new Point(1,0)
                                               << new Point(1,2) << new Point(2,1);
    QList<Point*> _strategy3 = QList<Point*>() << new Point(1,1);

public:
    Strategy();

    Point FirstMove(short x, short y);
};

#endif // STRATEGY_H
