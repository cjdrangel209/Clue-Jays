#pragma once

#include <QObject>
#include <iostream>
#include <streambuf>
#include <QString>

class ConsoleRedirector : public QObject, public std::streambuf
{
    Q_OBJECT
public:
    explicit ConsoleRedirector(QObject *parent = nullptr);
    ~ConsoleRedirector();

signals:
    void newOutput(const QString &text);

protected:
    int_type overflow(int_type v) override;
    std::streamsize xsputn(const char *p, std::streamsize n) override;

private:
    std::streambuf *originalCoutBuffer;
    QString buffer;
};
