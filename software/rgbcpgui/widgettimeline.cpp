#include "widgettimeline.h"
#include <QHeaderView>


WidgetTimeLine::WidgetTimeLine(QWidget *parent) :
    QTableWidget(parent),
    frameCount_(1),
    isReadOnly_(false)
{
    connect(this, SIGNAL(currentCellChanged(int,int,int,int)), SLOT(onCurrentCellChanged(int,int,int,int)));

    verticalHeader()->hide();
    horizontalHeader()->hide();

    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::SingleSelection);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    setRowCount(1);

    setFrameCount(1);
    setFrameIndex(0);
}

WidgetTimeLine::~WidgetTimeLine()
{
}

void WidgetTimeLine::setFrameCount(int frameCount)
{
    if (frameCount < 1)
        frameCount = 1;

    frameCount_ = frameCount;

    setColumnCount(frameCount);

    for (int i = 0; i < frameCount; ++i)
        setItem(0, i, new QTableWidgetItem(QString("%1").arg(i + 1)));

    resizeColumnsToContents();
    resizeRowsToContents();

    const int h = contentsMargins().top() + contentsMargins().bottom() + horizontalHeader()->height() + rowHeight(0) + horizontalScrollBar()->height();
    setMinimumHeight(h);
    setMaximumHeight(h);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

int WidgetTimeLine::getFrameCount() const
{
    return frameCount_;
}

void WidgetTimeLine::setFrameIndex(int frameIndex)
{
    if (frameIndex >= getFrameCount())
        frameIndex = getFrameCount() - 1;

    if (frameIndex < 0)
        frameIndex = 0;

    setCurrentCell(0, frameIndex);
}

int WidgetTimeLine::getFrameIndex() const
{
    return currentColumn();
}

bool WidgetTimeLine::isReadOnlyMode() const
{
    return isReadOnly_;
}

void WidgetTimeLine::setReadOnlyMode(bool isReadOnly)
{
    isReadOnly_ = isReadOnly;

    if (isReadOnly)
        setEnabled(false);
    else
        setEnabled(true);
}

void WidgetTimeLine::onCurrentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    Q_UNUSED(currentRow);
    Q_UNUSED(previousRow);
    Q_UNUSED(previousColumn);

    if (currentColumn >= 0 && !isReadOnlyMode())
    {
        emit timeLineFrameSelected(currentColumn);
    }
}
