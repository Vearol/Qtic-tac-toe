#include "MoveService.h"
#include <QQmlEngine>
#include <QQmlComponent>
#include <Strategy.h>
#include <QDebug>

MoveService::MoveService(QQmlApplicationEngine &engine)
{
    QQmlComponent component(&engine,QUrl(QStringLiteral("qrc:/main.qml")));
    object = component.create();
}

void MoveService::humanMove(const QString &cell)
{
    qDebug() << "Readed human sell: " << cell;
    short x = cell[0].toLatin1() - 48;
    short y = cell[1].toLatin1() - 48;

    _field[x][y] = 1;
    _moveCounter++;

    if (_moveCounter == 1){
        Strategy strategy;
        Point firstPont = strategy.FirstMove(x,y);
        InitializeMove(firstPont);
        return;
    }    
    CalculateMove();
}

void MoveService::restart()
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            _field[i][j] = 0;
    }
    _moveCounter = 0;
}

MoveTip MoveService::ForcedMove()
{
    short horizontalSum = 0;
    short verticalSum = 0;
    short diagonalSum1 = 0;
    short diagonalSum2 = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            horizontalSum += _field[i][j];
            verticalSum += _field[j][i];
            //qDebug() << horizontalSum << verticalSum;
        }

        if (horizontalSum >= 2 || horizontalSum <= -2)
            return MoveTip(Horizontal, i);

        if (verticalSum >= 2 || verticalSum <= -2)
            return MoveTip(Vertical, i);

        horizontalSum = 0;
        verticalSum = 0;

        diagonalSum1 += _field[i][i];
        diagonalSum2 += _field[i][2-i];
    }
    if (diagonalSum1 >= 2 || diagonalSum1 <= -2)
        return MoveTip(DiagonalLeft);
    if (diagonalSum2 >= 2 || diagonalSum2 <= -2)
        return MoveTip(DiagonalRight);

    return MoveTip(None);
}

void MoveService::CalculateMove()
{
    MoveTip tip = ForcedMove();

    if (tip.movePosition == Horizontal){
        qDebug() << "horizontal " << tip.moveSell;
        for (int i = 0; i < 3; i++){
            if (_field[tip.moveSell][i] == 0){
                Point newMove(tip.moveSell, i);
                qDebug() << newMove.ToString();
                return
                InitializeMove(newMove);
                return;
            }
        }
    }
    if (tip.movePosition == Vertical){
        qDebug() << "vertical " << tip.moveSell;
        for (int i = 0; i < 3; i++){
            //qDebug() << _field[i][tip.moveSell];
            if (_field[i][tip.moveSell] == 0){
                Point newMove(i, tip.moveSell);
                InitializeMove(newMove);
                return;
            }
        }
    }
    if (tip.movePosition == DiagonalLeft){
        qDebug() << "diagonal left";
        for (int i = 0; i < 3; i++){
            if (_field[i][i] == 0){
                Point newMove(i, i);
                qDebug() << newMove.ToString();
                InitializeMove(newMove);
                return;
            }
        }
    }
    if (tip.movePosition == DiagonalRight){
        qDebug() << "diagonal right";
        for (int i = 0; i < 3; i++){
            qDebug() << _field[i][2-i];
            if (_field[i][2-i] == 0){
                Point newMove(i, 2-i);
                qDebug() << newMove.ToString();
                InitializeMove(newMove);
                return;
            }
        }
    }
    if (tip.movePosition == None){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (_field[i][j] == 0){
                    Point newMove(i, j);
                    qDebug() << newMove.ToString();
                    InitializeMove(newMove);
                    return;
                }
            }
        }
    }
}

void MoveService::InitializeMove(Point &point)
{
    _field[point.X][point.Y] = -1;

    qDebug() << "CPU cell: " << point.ToString() << endl;
 //   QQmlEngine engine;
 //   QQmlComponent component(&engine,QUrl(QStringLiteral("qrc:/main.qml")));
 //   QObject *object = component.create();

    QObject *rect = object->findChild<QObject*>(point.ToString());
    if (rect)
        rect->setProperty("color", "red");

    //delete object;
}

QString Point::ToString()
{
    return QString::number(this->X) + QString::number(this->Y);
}
