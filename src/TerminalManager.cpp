#include "../header/TerminalManager.h"
#include <QDebug>
#include <QDateTime>

static TerminalManager* s_instance = nullptr;

TerminalManager::TerminalManager(QObject *parent) : QObject(parent)
{
    s_instance = this;
}

TerminalManager* TerminalManager::instance()
{
    return s_instance;
}

void TerminalManager::startRedirect()
{
    qInstallMessageHandler([](QtMsgType type, const QMessageLogContext &context, const QString &msg) {
        Q_UNUSED(context);
        QString formattedMessage = QDateTime::currentDateTime().toString("hh:mm:ss") + " | " + msg;
        if (TerminalManager::instance())
            emit TerminalManager::instance()->terminalOutput(formattedMessage);
    });
}
