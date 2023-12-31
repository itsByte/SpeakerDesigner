#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>

class TreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    TreeWidget(QWidget *parent);

private slots:
    void showMenu(const QPoint &pos);
};

#endif