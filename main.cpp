#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controllers/shopcontroller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    ShopController controller;

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("shopController", &controller);
    engine.rootContext()->setContextProperty("shopModel", controller.getShopModel());
    engine.rootContext()->setContextProperty("basketModel", controller.getBasketModel());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
