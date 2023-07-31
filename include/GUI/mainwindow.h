#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QStackedWidget>


#include "addclientdialog.h"
#include "mediamanagementwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 *
 * Implementation of the main GUI window.
 * Central element is a stacked window that switches between the 3 main views (client manager, media manager and main window)
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget* m_centralStackWidget; ///< main window uses a QStackWidget to switch between different views
    QWidget* m_centralWidget; ///< default central widget of QMainWindow (first member of m_centralStackWidget
    MediaManagementWidget* m_centralManagementWidget;
    QWidget *m_groupBoxTop;
    QGroupBox *m_groupBoxMediaManager;
    QGroupBox *m_groupBoxUserManager;
    QGroupBox *m_groupBoxLoanManager;
    AddClientDialog* m_client_dialog;


    void createActions();
    void createStatusBar();
    void createTopWidget();
    void createMediaManager();
    void createUserManager();
    void connectSignals();
    void about();
};
#endif // MAINWINDOW_H
