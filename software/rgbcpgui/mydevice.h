#ifndef MYDEVICE_H
#define MYDEVICE_H

#include <QObject>

class MyDevice : public QObject
{
    Q_OBJECT
public:
    explicit MyDevice(QObject *parent = 0);

signals:

public slots:

};

#endif // MYDEVICE_H
