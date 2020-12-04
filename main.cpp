#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "bookkeepinglist.h"
#include "bookkeepingmodel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<BookkeepingModel> ("Bookkeeping", 1, 0, "BookkeepingModel_qml");

    QQmlApplicationEngine engine;

    BookkeepingList double_entry;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
