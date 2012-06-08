#include "tabviewwidget.h"

TabViewWidget::TabViewWidget(QWidget *parent) : QWidget(parent)
{
}

void TabViewWidget::setSelectedRowIndex(QModelIndex &index)
{
    this->index = QPersistentModelIndex(index);

    if (this->index.isValid()) {
        QListIterator<QGraphicsView*> i (views);

        while (i.hasNext()) {
            const QGraphicsView *view = i.next();
            view->scene()->update();        // TODO: may need to override this (or other function or slot) in subclass?
        }
    }
}

void TabViewWidget::setRow(StreamTableRow *row)
{
}