#ifndef BODEPLOT_H
#define BODEPLOT_H

#include <QPointF>
#include <QWidget>
#include <QwtPlot>

class BodePlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit BodePlot(QWidget *parent = nullptr);
    void Populate(QList<QPointF> list);
};

#endif // PLOT_H