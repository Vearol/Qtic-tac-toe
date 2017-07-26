#ifndef MOVESERVICE_H
#define MOVESERVICE_H

#include <QString>
#include <QObject>
#include <QQmlApplicationEngine>

enum Position{
    Vertical,
    Horizontal,
    DiagonalLeft,
    DiagonalRight,
    None
};

struct Point{
public:
    short X;
    short Y;

    Point(short x, short y) { X = x; Y = y; }

    QString ToString();

    bool operator==(const Point& other)const
    {
        if(this->X==(other.X) && this->Y==(other.Y))
        {
            return true;
        }
        return false;
    }
};

struct MoveTip{
public:
    Position movePosition;
    short moveSell;

    MoveTip(const Position &pos) { movePosition = pos; }
    MoveTip(const Position &pos, short sell) { movePosition = pos; moveSell = sell; }
};

class MoveService : public QObject
{
    Q_OBJECT
private:
    short _field[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

    MoveTip ForcedMove();

    void CalculateMove();
    void InitializeMove(Point &point);
    bool CPUWin();

    short _moveCounter = 0;
    QObject* object;
    QQmlContext* context;
public:
    MoveService(QQmlApplicationEngine &engine);

    Q_INVOKABLE void humanMove(const QString &cell);
    Q_INVOKABLE void restart();
};

#endif // MOVESERVICE_H
