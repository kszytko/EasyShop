#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "shopcontroller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //auto shopController = std::make_unique<ShopController>();
    ShopController controller(":/data.json");

    engine.rootContext()->setContextProperty("shopController", &controller);
    engine.rootContext()->setContextProperty("shopModel", controller.getShopModel());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
