/*#include "../header/ClueLess.h"
#include <iostream>
#include <QApplication>
#include <QPushButton>

int main() {
	std::cout << "Hello, World!" << std::endl;
	ClueLess c = ClueLess();
	return 0;
}*/

/*#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Load the QML file
    const QUrl url(QUrl::fromLocalFile("C:/Users/hdeyt/Documents/grad_school/software_eng/spare/ClueJaysUI2.0/ClueJays/ClueJaysContent/Screen01.ui.qml"));//(u"qrc:/Screen01.ui.qml"_qs);  // Or use QUrl::fromLocalFile(...) if not using resources
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}*/

/*#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "../header/TerminalManager.h"
#include "../header/ConsoleRedirector.h"
#include <fstream>
#include "../header/ClueLess.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    TerminalManager terminalManager;
    terminalManager.startRedirect();
    engine.rootContext()->setContextProperty("terminalManager", &terminalManager);

    ConsoleRedirector redirector;
    QObject::connect(&redirector, &ConsoleRedirector::newOutput,
        &terminalManager, &TerminalManager::terminalOutput);

    //const QUrl url(QUrl::fromLocalFile("C:/Users/hdeyt/Documents/grad_school/software_eng/Clue-Jays/src/Screen01.ui.qml"));
    const QUrl url(QUrl::fromLocalFile("Screen01.ui.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    emit terminalManager.terminalOutput("Direct C++ message test.");

    
    std::cout << "std::cout now goes to QML terminal!" << std::endl;

    //return app.exec();
    app.exec();
    //ClueLess c = ClueLess();
}*/

/*#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <iostream>
#include "../header/ClueLess.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Load your QML file
    const QUrl url(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Screen01.ui.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.load(url);


    return app.exec();
}*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include "../src/ConsoleRedirector.cpp"
#include "../header/ClueLess.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Install console redirector
    ConsoleRedirector redirector;
    engine.rootContext()->setContextProperty("consoleRedirector", &redirector);

    const QUrl url(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Screen01.ui.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    engine.load(url);

    // Run ClueLess game in a separate thread
    QThread* gameThread = QThread::create([]() {
        ClueLess clueJay;
        });
    gameThread->start();

    return app.exec();
}





