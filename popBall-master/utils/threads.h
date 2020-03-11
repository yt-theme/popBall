#ifndef THREADS_H
#define THREADS_H

#include <QObject>

class Threads : public QObject
{
    Q_OBJECT
public:
    explicit Threads(QObject *parent = nullptr);
    ~Threads();

    void doWork(); // thread do something

signals:
    void dataSignal(); // signal for data
};

#endif // THREADS_H
