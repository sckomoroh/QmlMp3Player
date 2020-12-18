#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "RootContext.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    RootContext rootContext;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("rootContext", &rootContext);
    const QUrl url(QStringLiteral("qrc:/views/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
