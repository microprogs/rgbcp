#ifndef WIDGETTIMELINE_H
#define WIDGETTIMELINE_H


#include <QTableWidget>
#include <QScrollBar>


class WidgetTimeLine : public QTableWidget
{
    Q_OBJECT

public:
    explicit WidgetTimeLine(QWidget *parent = 0);
    virtual ~WidgetTimeLine();

    void setFrameCount(int frameCount);
    int getFrameCount() const;

    void setFrameIndex(int frameIndex);
    int getFrameIndex() const;

    bool isReadOnlyMode() const;
    void setReadOnlyMode(bool isReadOnly);

signals:
    void timeLineFrameSelected(int index);

private slots:
    void onCurrentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

public slots:

private:
    int frameCount_;
    bool isReadOnly_;
};

#endif // WIDGETTIMELINE_H
