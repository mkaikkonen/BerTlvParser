#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "bertlvparser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Register class as QML library
    qmlRegisterType<BerTlvParser>("BerTlvParser", 1, 0, "BerTlvParser");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
