#include "widgetleds.h"
#include <math.h>
#include "colorconverter.h"
#include <QApplication>
#include <QClipboard>


WidgetLeds::WidgetLeds(QWidget *parent) :
    QWidget(parent),
    isReadOnly_(false)
{
    contextMenu = new QMenu(this);
    contextMenu->addAction("&Copy", this, SLOT(actionMenuCopy()));
    contextMenu->addAction("&Paste", this, SLOT(actionMenuPaste()));

    setMinimumWidth(pointConverter_.screenWidth());
    setMinimumHeight(pointConverter_.screenHeight());

    setMouseTracking(true);
}

WidgetLeds::~WidgetLeds()
{
    delete contextMenu;
}

void WidgetLeds::setReadOnlyMode(bool isReadOnly)
{
    isReadOnly_ = isReadOnly;

    setMouseTracking(!isReadOnly);

    update();
}

bool WidgetLeds::isReadOnlyMode() const
{
    return isReadOnly_;
}

void WidgetLeds::setLedFrame(const LedFrame &frame)
{
    ledFrame_ = frame;
    update();
}

LedFrame WidgetLeds::getLedFrame() const
{
    return ledFrame_;
}

void WidgetLeds::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    drawFrame(painter, ledFrame_);
    painter.end();
}

void WidgetLeds::mousePressEvent(QMouseEvent *event)
{
    if (!isReadOnlyMode() && event->button() == Qt::LeftButton)
    {
        mousePressEventLeft(event);
    }

    QWidget::mousePressEvent(event);
}

void WidgetLeds::mouseReleaseEvent(QMouseEvent *event)
{
    if (!isReadOnlyMode() && event->button() == Qt::RightButton)
    {
        mouseReleaseEventRight(event);
    }

    QWidget::mouseReleaseEvent(event);
}

void WidgetLeds::mousePressEventLeft(QMouseEvent *event)
{
    const QPoint pos = event->pos();

    bool isDelayChanged = false;
    if (pointConverter_.isPointDelay(pos))
    {
        DialogDelay ddl(this);
        ddl.setFrameDelay(ledFrame_.getDelay());

        if (ddl.exec() == QDialog::Accepted)
        {
            ledFrame_.setDelay(ddl.getFrameDelay());
            isDelayChanged = true;
        }

        update();
    }

    bool isColorChanged = false;
    int row = 0, col = 0;
    if (pointConverter_.isPointLed(pos, row, col))
    {
        DialogLedColor dlc(this);
        FullNColor old_color = ledFrame_.getLedColor(row, col);
        dlc.setLedColor(old_color.subColorRed.ncolor, old_color.subColorGreen.ncolor, old_color.subColorBlue.ncolor);

        if (dlc.exec() == QDialog::Accepted)
        {
            uint cred = 0, cgreen = 0, cblue = 0;
            dlc.getLedColor(cred, cgreen, cblue);

            ledFrame_.setLedColor(row, col, FullNColor(cred, cgreen, cblue));
            isColorChanged = true;
        }

        update();
    }

    if (isDelayChanged || isColorChanged)
    {
        emit ledFrameChanged();
    }
}

void WidgetLeds::mouseReleaseEventRight(QMouseEvent *event)
{
    Q_UNUSED(event);
    showContextMenu(isLedFrameInClipboard());
}

void WidgetLeds::mouseMoveEvent(QMouseEvent *event)
{
    bool isInDelay = false;
    bool isInLed = false;

    if (!isReadOnlyMode() && pointConverter_.isPointDelay(event->pos()))
    {
        isInDelay = true;
        QToolTip::showText(event->globalPos(),
                           QString("Delay: %1  --  Click To Edit").arg(ledFrame_.getDelay()),
                           this, rect());
    }

    int row = 0, col = 0;
    if (!isReadOnlyMode() && pointConverter_.isPointLed(event->pos(), row, col))
    {
        isInLed = true;
        const FullNColor color = ledFrame_.getLedColor(row, col);
        const uint nred = color.subColorRed.ncolor;
        const uint ngreen = color.subColorGreen.ncolor;
        const uint nblue = color.subColorBlue.ncolor;
        QToolTip::showText(event->globalPos(),
                           QString("LED[%1, %2]: RGB(%3, %4, %5)  --  Click To Edit").arg(row).arg(col).arg(nred).arg(ngreen).arg(nblue),
                           this, rect());
    }

    if (!isInDelay && !isInLed)
        QToolTip::hideText();

    QWidget::mouseMoveEvent(event);  // Or whatever the base class is.
}

void WidgetLeds::drawBackground(QPainter &painter)
{
    painter.setPen(QPen(QColor(Qt::black)));
    painter.setBrush(QBrush(QColor(Qt::white)));
    painter.drawRect(0, 0, pointConverter_.screenWidth()-1, pointConverter_.screenHeight()-1);
}

void WidgetLeds::drawLedRGB(QPainter &painter, QPoint center, uint nred, uint ngreen, uint nblue)
{
    const int led_radius = pointConverter_.screenLedRadius();

    // bits per color
    const uint red_bits = ColorConverter::bitsPerRed();  // 0..7
    const uint green_bits = ColorConverter::bitsPerGreen();  // 0..7
    const uint blue_bits = ColorConverter::bitsPerBlue();  // 0..3

    // fix colors by bits
    nred = ColorConverter::fixSubColorBitsRed(nred);  // 0..7
    ngreen = ColorConverter::fixSubColorBitsGreen(ngreen);  // 0..7
    nblue = ColorConverter::fixSubColorBitsBlue(nblue);  // 0..3

    // get real colors in canvas  
    const QColor colorSubRed = ColorConverter::convertSubColorToRealColor(nred, red_bits, Qt::red);
    const QColor colorSubGreen = ColorConverter::convertSubColorToRealColor(ngreen, green_bits, Qt::green);
    const QColor colorSubBlue = ColorConverter::convertSubColorToRealColor(nblue, blue_bits, Qt::blue);

    const QColor colorFullLed = ColorConverter::convertFullColorToRealColor(nred, ngreen, nblue);

    // draw led color
    painter.setPen(QPen(QColor(Qt::black)));
    painter.setBrush(QBrush(colorFullLed));
    painter.drawEllipse(center, led_radius, led_radius);

    // draw subcolor: red
    drawSubLed(painter, QRectF(center.x() - led_radius/2, center.y() + led_radius/2 - led_radius/4, led_radius, led_radius/2),
               colorSubRed, QString::number(nred));

    // draw subcolor: green
    drawSubLed(painter, QRectF(center.x() - led_radius/2, center.y() - led_radius/4, led_radius, led_radius/2),
               colorSubGreen, QString::number(ngreen));

    // draw subcolor: blue
    drawSubLed(painter, QRectF(center.x() - led_radius/2, center.y() - led_radius/2 - led_radius/4, led_radius, led_radius/2),
               colorSubBlue, QString::number(nblue));
}

void WidgetLeds::drawSubLed(QPainter &painter, QRectF rectf, QColor color, QString text)
{
    painter.setPen(QPen(QColor(Qt::black)));
    painter.setBrush(QBrush(color));
    painter.drawRect(rectf);
    painter.drawText(rectf, Qt::AlignCenter, text);
}

void WidgetLeds::drawDelay(QPainter &painter, QRect rect, quint16 delayValue)
{
    const QString text = QString("Delay:\n%1").arg(delayValue);

    QPen pen = QPen(QColor(Qt::black));
    pen.setWidth(2);
    painter.setPen(pen);

    painter.setBrush(QBrush(QColor(Qt::lightGray)));

    painter.drawRect(rect);
    painter.drawText(rect, Qt::AlignCenter, text);
}

void WidgetLeds::drawFrame(QPainter &painter, const LedFrame &frame)
{
    drawBackground(painter);

    for (int row = 0; row < frame.rowCount(); ++row)
    {
        for (int col = 0; col < frame.colCount(); ++col)
        {
            QPoint ledPoint;
            if (pointConverter_.matrixPointToScreenPoint(row, col, ledPoint))
            {
                const FullNColor ledFullNColor = frame.getLedColor(row, col);

                const uint nred = ledFullNColor.subColorRed.ncolor;
                const uint ngreen = ledFullNColor.subColorGreen.ncolor;
                const uint nblue = ledFullNColor.subColorBlue.ncolor;

                drawLedRGB(painter, ledPoint, nred, ngreen, nblue);
            }
        }
    }

    if (!isReadOnlyMode())
        drawDelay(painter, pointConverter_.delayRect(), frame.getDelay());
}

void WidgetLeds::showContextMenu(bool isPaste)
{
    QList<QAction *> actions = contextMenu->actions();

    foreach (QAction *act, actions)
    {
        if (act->text() == "&Paste")
        {
            act->setEnabled(isPaste);
        }
    }

    contextMenu->exec(QCursor::pos());
}

bool WidgetLeds::isLedFrameInClipboard() const
{
    QClipboard *clipboard = QApplication::clipboard();

    LedFrame lf;
    if (lf.fromText(clipboard->text()))
        return true;

    return false;
}

void WidgetLeds::actionMenuCopy()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(getLedFrame().toText());
}

void WidgetLeds::actionMenuPaste()
{
    if (isLedFrameInClipboard())
    {
        QClipboard *clipboard = QApplication::clipboard();

        LedFrame lf;
        if (lf.fromText(clipboard->text()))
        {
            setLedFrame(lf);
            emit ledFrameChanged();
        }
    }
}
