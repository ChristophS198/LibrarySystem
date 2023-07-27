#ifndef MEDIAMANAGEMENTWIDGET_H
#define MEDIAMANAGEMENTWIDGET_H

#include <QObject>
#include <QWidget>

class MediaManagementWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MediaManagementWidget(QWidget *parent = nullptr);

signals:
    void goBackToMainView();
};

#endif // MEDIAMANAGEMENTWIDGET_H
