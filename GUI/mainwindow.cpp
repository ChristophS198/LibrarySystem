#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createTopWidget();
    createMediaManager();
    createUserManager();

    createActions();
    createStatusBar();

    m_client_dialog = new ClientDialog(this); // should this be created when needed?

    connect(m_AddClientButton, &QPushButton::clicked, m_client_dialog, &ClientDialog::exec);
    this->resize(800, 500);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createTopWidget()
{
    // Set layout in central Widget
    m_centralWidget = new QWidget(this);
    m_centralManagementWidget = new QWidget(this);
    QVBoxLayout *centralWidgetLayout = new QVBoxLayout;
    m_centralWidget->setLayout(centralWidgetLayout);
    m_centralStackWidget = new QStackedWidget(this);
    m_centralStackWidget->addWidget(m_centralWidget);
    m_centralStackWidget->addWidget(m_centralManagementWidget);

    // Set QStackWidget as the central layout of the main window
    setCentralWidget(m_centralStackWidget);
    m_centralStackWidget->setCurrentIndex(0);

    m_groupBoxTop = new QWidget(this);
    m_groupBoxMediaManager = new QGroupBox(tr("Media Manager"), this);
    m_groupBoxUserManager = new QGroupBox(tr("User Manager"), this);
    m_groupBoxLoanManager = new QGroupBox(tr("Loan Manager"), this);
    // Set layout
    centralWidgetLayout->addWidget(m_groupBoxTop);
    centralWidgetLayout->addWidget(m_groupBoxMediaManager);
    centralWidgetLayout->addWidget(m_groupBoxUserManager);
    centralWidgetLayout->addWidget(m_groupBoxLoanManager);

    QGridLayout *layoutTopWidget = new QGridLayout;
    QLabel *welcomeLabel = new QLabel(tr("Welcome to your\nLibrary Managment System"), m_groupBoxTop);
    layoutTopWidget->addWidget(welcomeLabel);
    m_groupBoxTop->setLayout(layoutTopWidget);

}

void MainWindow::createMediaManager()
{
    QHBoxLayout *layoutMediaManager = new QHBoxLayout;
    QLabel *mediaLabel = new QLabel(tr("Manage Media"), m_groupBoxMediaManager);
    layoutMediaManager->addWidget(mediaLabel);

    QPushButton *openMediaManagementButton = new QPushButton("Open Media Management");
    layoutMediaManager->addWidget(openMediaManagementButton);

    QPixmap logoPixmap(":/Icons/book.svg"); // set your logo here
    auto bookLabel = new QLabel(m_groupBoxUserManager);
    bookLabel->setPixmap(logoPixmap);
    bookLabel->setScaledContents(true);
    bookLabel->setFixedSize(64, 64); // set your size here
    layoutMediaManager->addWidget(bookLabel);

    m_groupBoxMediaManager->setLayout(layoutMediaManager);

    connect(openMediaManagementButton, &QPushButton::clicked, this, [&](){m_centralStackWidget->setCurrentIndex(1);});
}

void MainWindow::createUserManager()
{
    QHBoxLayout *layoutUserManager = new QHBoxLayout;
    QLabel *userLabel = new QLabel(tr("Manage Clients"), m_groupBoxUserManager);
    layoutUserManager->addWidget(userLabel);

    m_AddClientButton = new QPushButton("Add Client");
    layoutUserManager->addWidget(m_AddClientButton);

    QPixmap logoPixmap(":/Icons/person-circle2.svg"); // set your logo here
    auto personLabel = new QLabel(m_groupBoxUserManager);
    personLabel->setPixmap(logoPixmap);
    personLabel->setScaledContents(true);
    personLabel->setFixedSize(64, 64); // set your size here
    layoutUserManager->addWidget(personLabel);


    m_groupBoxUserManager->setLayout(layoutUserManager);

}

void MainWindow::createActions()
{
    // File Menu
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));
    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newAct = new QAction(newIcon, tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));

    // View Menu
    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));
    QAction *switchToMediaManagementViewAction = viewMenu->addAction(tr("&MediaManagement"), this, [&](){m_centralStackWidget->setCurrentIndex(1);});
    switchToMediaManagementViewAction->setStatusTip(tr("Change to MediaManagement View"));
    QAction *switchToMainViewAction = viewMenu->addAction(tr("&MainView"), this, [&](){m_centralStackWidget->setCurrentIndex(0);});
    switchToMainViewAction->setStatusTip(tr("Change to Main View"));

    // Help Menu
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}
