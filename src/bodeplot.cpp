#include "bodeplot.h"
#include <QPen>
#include <QwtLogScaleEngine>
#include <QwtPlotOpenGLCanvas>
#include <QwtPlotCurve>

BodePlot::BodePlot(QWidget *parent) : QwtPlot()
{
    auto canv = new QwtPlotOpenGLCanvas;
    canv->setFrameStyle(QFrame::NoFrame);
    setCanvas(canv);
    setAxisScaleEngine(xBottom, new QwtLogScaleEngine);
    setFrameStyle(QFrame::NoFrame);
    setAxisScale(xBottom, 10, 20000);
    setAxisScale(yLeft, 40, 110);
}

void BodePlot::Populate(QList<QPointF> list)
{
    auto curve = new QwtPlotCurve;
    curve->setRenderHint(QwtPlotItem::RenderAntialiased);
    curve->setLegendAttribute(QwtPlotCurve::LegendShowLine, true);
    curve->setPen(QPen(Qt::red));
    curve->setSamples(list);
    curve->attach(this);
}