#pragma once

#include <QObject>
#include <QString>

class TerminalManager : public QObject
{
    Q_OBJECT
public:
    explicit TerminalManager(QObject *parent = nullptr);
    static TerminalManager* instance();
    void startRedirect();

signals:
    void terminalOutput(const QString &output);
};
