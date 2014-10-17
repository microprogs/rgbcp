#ifndef WIDGETLEDS_H
#define WIDGETLEDS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QToolTip>
#include "pointconverter.h"
#include "ledframe.h"
#include "dialogledcolor.h"
#include "dialogdelay.h"
#include <QMenu>


class WidgetLeds : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetLeds(QWidget *parent = 0);
    virtual ~WidgetLeds();

    void setReadOnlyMode(bool isReadOnly);
    bool isReadOnlyMode() const;

    void setLedFrame(const LedFrame &frame);
    LedFrame getLedFrame() const;

protected:
   void paintEvent(QPaintEvent *event);

   void mousePressEvent(QMouseEvent *event);
   void mousePressEventLeft(QMouseEvent *event);

   void mouseReleaseEvent(QMouseEvent *event);
   void mouseReleaseEventRight(QMouseEvent *event);

   void mouseMoveEvent(QMouseEvent *event);

   void drawBackground(QPainter &painter);
   void drawLedRGB(QPainter &painter, QPoint center, uint nred, uint ngreen, uint nblue);
   void drawSubLed(QPainter &painter, QRectF rectf, QColor color, QString text);
   void drawDelay(QPainter &painter, QRect rect, quint16 delayValue);
   void drawFrame(QPainter &painter, const LedFrame &frame);

   void showContextMenu(bool isPaste);
   bool isLedFrameInClipboard() const;

signals:
   void ledFrameChanged();

private slots:
   void actionMenuCopy();
   void actionMenuPaste();

private:
   bool isReadOnly_;
   LedFrame ledFrame_;
   PointConverter pointConverter_;

   QMenu *contextMenu;
};


#endif // WIDGETLEDS_H
