#include "treewidget.h"

#include <QMenu>
#include <QAction>
#include <QTreeWidget>

TreeWidget::TreeWidget(QWidget *parent)
    : QTreeWidget(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setHeaderHidden(true);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showMenu(const QPoint &)));
}

void TreeWidget::showMenu(const QPoint &pos)
{
    QMenu menu;
    QTreeWidgetItem *nd = this->itemAt(pos);
    QPoint pt(pos);
    menu.addAction("Menu Item 1");
    QAction *selectedItem = menu.exec(this->mapToGlobal(pos));
}