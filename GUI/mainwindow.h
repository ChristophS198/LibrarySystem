#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QStackedWidget>


#include "clientdialog.h"
#include "mediamanagementwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget* m_centralStackWidget;
    QWidget* m_centralWidget;
    MediaManagementWidget* m_centralManagementWidget;
    QWidget *m_groupBoxTop;
    QGroupBox *m_groupBoxMediaManager;
    QGroupBox *m_groupBoxUserManager;
    QGroupBox *m_groupBoxLoanManager;

    QPushButton* m_AddClientButton;
    ClientDialog* m_client_dialog;

    void createActions();
    void createStatusBar();
    void createTopWidget();
    void createMediaManager();
    void createUserManager();
    void about();
};
#endif // MAINWINDOW_H
