#ifndef AMPLIFIER_H
#define AMPLIFIER_H

#include <QPointF>
#include <QWidget>
#include <QTreeWidgetItem>

class Amplifier : public QTreeWidgetItem
{
    Q_OBJECT
public:
    explicit BodePlot(QWidget *parent = nullptr);
    void Populate(QList<QPointF> list);
};

#endif // PLOT_H