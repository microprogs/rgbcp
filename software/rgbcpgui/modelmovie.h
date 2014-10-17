#ifndef MODELMOVIE_H
#define MODELMOVIE_H


#include <QObject>
#include <QList>
#include "ledframe.h"
#include <QByteArray>
#include <QString>


class ModelMovie : public QObject
{
    Q_OBJECT

public:
    explicit ModelMovie(QObject *parent = 0);
    virtual ~ModelMovie();

    bool LoadFromFile(const QString &fileName);
    bool SaveToFile(const QString &fileName) const;

    void clearAll();

    int frameCount() const;
    void insertFrameBefore(int index);
    void insertFrameAfter(int index);
    void deleteFrame(int index);

    void setFrame(int index, const LedFrame &ledFrame);
    LedFrame getFrame(int index) const;
    void clearFrame(int index);

signals:

public slots:

private:
    QList<LedFrame> ledFrameList_;
};


#endif // MODELMOVIE_H
