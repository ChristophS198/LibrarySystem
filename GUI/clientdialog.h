#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>



class ClientDialog : public QDialog
{
Q_OBJECT
public:
    explicit ClientDialog(QWidget* parent = nullptr);

private:
    QPushButton* m_button0;
    QLabel* m_label1;
    QLabel* m_label2;
    QVBoxLayout* m_layout;

};

#endif // CLIENTDIALOG_H
