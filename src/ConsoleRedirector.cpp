#ifndef CONSOLEREDIRECTOR_H
#define CONSOLEREDIRECTOR_H

#include <QObject>
#include <QString>
#include <streambuf>
#include <iostream>

class ConsoleRedirector : public QObject, public std::streambuf {
    Q_OBJECT
public:
    explicit ConsoleRedirector(QObject* parent = nullptr) : QObject(parent) {
        oldCout = std::cout.rdbuf(this);  // Replace std::cout buffer
    }

    ~ConsoleRedirector() {
        std::cout.rdbuf(oldCout);  // Restore original std::cout buffer on destruction
    }

signals:
    void newOutput(const QString& text);

protected:
    int overflow(int c) override {
        if (c == '\n') {
            emit newOutput(buffer);
            buffer.clear();
        }
        else {
            buffer += QChar(c);
        }
        return c;
    }

private:
    std::streambuf* oldCout;
    QString buffer;
};

#endif // CONSOLEREDIRECTOR_H
