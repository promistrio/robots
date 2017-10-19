#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "field.h"
#include "robots.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Field fieldModel(80, 40);

    Robots robotsModel(&fieldModel);


    QQmlApplicationEngine engine;

    QQmlContext * ctx = engine.rootContext();
    ctx->setContextProperty("fieldModel", &fieldModel);
    ctx->setContextProperty("robotsModel", &robotsModel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
