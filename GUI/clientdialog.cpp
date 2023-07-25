#include "clientdialog.h"


ClientDialog::ClientDialog(QWidget *parent) : QDialog(parent)
{
    setFixedSize(150,100);

    auto vbox = new QVBoxLayout(this);
    auto *label = new QLabel("Dialog for adding new Clients", this);

    auto *bOk = new QPushButton("Finished", this);
    auto *bCancel = new QPushButton("Cancel", this);
    bCancel->setDefault(true);
    vbox->addWidget(label);
    vbox->addWidget(bOk);
    vbox->addWidget(bCancel);

    connect(bCancel, &QPushButton::clicked, this, &ClientDialog::reject);
}
