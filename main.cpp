#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <MoveService.h>
#include <QQmlComponent>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    MoveService moveService(engine);

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("moveService", &moveService);

    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

