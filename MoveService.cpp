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
    if (SomeoneWin() > 0){
        QObject *text = object->findChild<QObject*>("endGameText");
        if (text)
            text->setProperty("text", "YOU WIN");
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

    for (int i = 1; i <= 9; i++){
        QObject *area = object->findChild<QObject*>(QString::number(i));
        if (area)
            area->setProperty("enabled", "true");
    }
}

MoveTip MoveService::ForcedMove()
{
    short horizontalSum = 0;
    short verticalSum = 0;
    short diagonalSum1 = 0;
    short diagonalSum2 = 0;

    MoveTip* moveTip;
    moveTip = new MoveTip(None);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            horizontalSum += _field[i][j];
            verticalSum += _field[j][i];
            //qDebug() << horizontalSum << verticalSum;
        }

        if (horizontalSum <= -2)
            return MoveTip(Horizontal, i);
        if (horizontalSum >= 2)
            moveTip = new MoveTip(Horizontal, i);

        if (verticalSum <= -2)
            return MoveTip(Vertical, i);
        if (verticalSum >= 2)
            moveTip = new MoveTip(Vertical, i);

        horizontalSum = 0;
        verticalSum = 0;

        diagonalSum1 += _field[i][i];
        diagonalSum2 += _field[i][2-i];
    }
    if (diagonalSum1 <= -2)
        return MoveTip(DiagonalLeft);
    if (diagonalSum1 >= 2)
        moveTip = new MoveTip(DiagonalLeft);
    if (diagonalSum2 <= -2)
        return MoveTip(DiagonalRight);
    if (diagonalSum2 >= 2)
        moveTip = new MoveTip(DiagonalRight);


    return *moveTip;
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
        short xRand = qrand() % 3;
        short yRand = qrand() % 3;
        int i = 0;
        while (_field[xRand][yRand] != 0){
            xRand = qrand() % 3;
            yRand = qrand() % 3;
            i++;
            if (i > 100) break;
        }
        Point newMove(xRand, yRand);
        qDebug() << newMove.ToString();
        InitializeMove(newMove);
        return;
    }
}

void MoveService::InitializeMove(Point &point)
{
    _field[point.X][point.Y] = -1;

    QObject *rect = object->findChild<QObject*>(point.ToString());
    if (rect)
        //rect->setProperty("color", "red");
        rect->setProperty("source", "qrc:/img/o.png");
    QObject *areaDisable = object->findChild<QObject*>(QString::number(3*point.X + point.Y + 1));
    if (areaDisable)
        areaDisable->setProperty("enabled", "false");

    short winType = SomeoneWin();
    qDebug() << winType;
    if (winType != 0){
        QObject *text = object->findChild<QObject*>("endGameText");
        if (text)
            if (winType == 1)
                text->setProperty("text", "YOU WIN");
            if (winType == -1)
                text->setProperty("text", "YOU LOSE");
        for (int i = 1; i <= 9; i++){
            QObject *area = object->findChild<QObject*>(QString::number(i));
            if (area)
                area->setProperty("enabled", "false");
        }
    }

    //delete object;
}

short MoveService::SomeoneWin()
{
    short horizontalSum = 0;
    short verticalSum = 0;
    short diagonalSum1 = 0;
    short diagonalSum2 = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            horizontalSum += _field[i][j];
            verticalSum += _field[j][i];
        }

        if (horizontalSum == 3)
            return 1;

        if (verticalSum == 3)
            return 1;

        if (horizontalSum == -3)
            return -1;

        if (verticalSum == -3)
            return -1;

        horizontalSum = 0;
        verticalSum = 0;

        diagonalSum1 += _field[i][i];
        diagonalSum2 += _field[i][2-i];
    }
    if (diagonalSum1 == -3)
        return -1;
    if (diagonalSum2 == -3)
        return -1;

    if (diagonalSum1 == 3)
        return 1;
    if (diagonalSum2 == 3)
        return 1;

    return 0;
}

QString Point::ToString()
{
    return QString::number(this->X) + QString::number(this->Y);
}
