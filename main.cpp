#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "shopcontroller.h"
#include "networkhandler.h"
#include "filehandler.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    NetworkHandler networkHandler("http://127.0.0.1:5000/getProducts");
    FileHandler fileHandler(":/data.json");

    ShopController controller(&fileHandler);

    engine.rootContext()->setContextProperty("shopController", &controller);
    engine.rootContext()->setContextProperty("shopModel", controller.getShopModel());
    engine.rootContext()->setContextProperty("basketModel", controller.getBasketModel());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
