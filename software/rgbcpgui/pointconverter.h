#ifndef POINTCONVERTER_H
#define POINTCONVERTER_H

#include <QVector>
#include <QPair>
#include <QPoint>
#include <QRect>


class PointConverter
{
public:
    explicit PointConverter();
    virtual ~PointConverter();

    int screenWidth() const;
    int screenHeight() const;

    int screenLedRadius() const;

    QRect delayRect() const;

    int matrixRowCount() const;
    int matrixColCount() const;

    bool matrixPointToScreenPoint(int row, int col, QPoint &screenPoint) const;

    bool isPointDelay(QPoint point) const;
    bool isPointLed(QPoint point, int &matrix_row, int &matrix_col) const;

protected:
    bool screenPointToMatrixPoint(const QPoint &screenPoint, int &matrix_row, int &matrix_col) const;
    double calcDistanceBetweenPoints(const QPoint &p1, const QPoint &p2) const;
    QVector<QPoint> screenLedPointsList() const;

private:
    QVector<QVector<QPoint> > mapMatrixToScreen_;

    void initMap();
    void initPoints(QVector<QVector<QPoint> > &matrix, const QPointF &pos, const QPointF &scale);
};

#endif // POINTCONVERTER_H
