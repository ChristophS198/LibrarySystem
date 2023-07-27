#include <QGroupBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QComboBox>
#include <QDateTimeEdit>

#include "addclientdialog.h"


AddClientDialog::AddClientDialog(QWidget *parent) : QDialog(parent)
{
    //setFixedSize(150,100);

    auto *m_dialogLayout = new QVBoxLayout(this);

    // Personal data
    QGroupBox *groupBoxPersonalData = new QGroupBox(tr("Personal Data"), this);
    QGridLayout *layoutPersonalData = new QGridLayout;
    auto *firstNameLabel = new QLabel("First Name: ", groupBoxPersonalData);
    auto *lastNameLabel = new QLabel("Last Name: ", groupBoxPersonalData);
    auto *firstNameTextEdit = new QLineEdit(groupBoxPersonalData);
    auto *lastNameTextEdit = new QLineEdit(groupBoxPersonalData);
    auto *genderLabel = new QLabel("Gender: ", groupBoxPersonalData);
    auto *genderComboBox = new QComboBox();
    genderComboBox->addItem("Male", "Male");
    genderComboBox->addItem("Female", "Female");
    genderComboBox->addItem("Divers", "Divers");
    genderComboBox->addItem("-", "-");
    genderComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    genderComboBox->setCurrentIndex(genderComboBox->findData("-"));
    auto *dateOfBirthLabel = new QLabel("Date of Birth: ", groupBoxPersonalData);
    auto *dateOfBirthDateEdit = new QDateEdit(groupBoxPersonalData);
    dateOfBirthDateEdit->setCalendarPopup(true);
    dateOfBirthDateEdit->setDisplayFormat("dd.MM.yyyy");

    // Layout
    layoutPersonalData->addWidget(firstNameLabel,0,0);
    layoutPersonalData->addWidget(lastNameLabel,1,0);
    layoutPersonalData->addWidget(firstNameTextEdit,0,1);
    layoutPersonalData->addWidget(lastNameTextEdit,1,1);
    layoutPersonalData->addWidget(genderLabel,2,0);
    QHBoxLayout *genderLayout = new QHBoxLayout;
    genderLayout->addWidget(genderComboBox);
    genderLayout->addStretch();
    layoutPersonalData->addLayout(genderLayout,2,1);
    layoutPersonalData->addWidget(dateOfBirthLabel,3,0);
    layoutPersonalData->addWidget(dateOfBirthDateEdit,3,1);
    groupBoxPersonalData->setLayout(layoutPersonalData);

    // Contact data
    QGroupBox *groupBoxContactData = new QGroupBox(tr("Contact Data"), this);
    QGridLayout *layoutContactData = new QGridLayout;
    auto *mailAddressLabel = new QLabel("Mail address: ", groupBoxContactData);
    auto *mobileNumberLabel = new QLabel("Mobile number: ", groupBoxContactData);
    auto *mailAddressTextEdit = new QLineEdit(groupBoxContactData);
    auto *mobileNumberTextEdit = new QLineEdit(groupBoxContactData);
    layoutContactData->addWidget(mailAddressLabel,0,0);
    layoutContactData->addWidget(mobileNumberLabel,1,0);
    layoutContactData->addWidget(mailAddressTextEdit,0,1);
    layoutContactData->addWidget(mobileNumberTextEdit,1,1);
    groupBoxContactData->setLayout(layoutContactData);

    // save/close buttons
    auto *bOk = new QPushButton("Finished", this);
    auto *bCancel = new QPushButton("Cancel", this);
    bCancel->setDefault(true);

    // layout
    m_dialogLayout->addWidget(groupBoxPersonalData);
    m_dialogLayout->addWidget(groupBoxContactData);
    m_dialogLayout->addWidget(bOk);
    m_dialogLayout->addWidget(bCancel);
    this->setLayout(m_dialogLayout);

    this->setWindowTitle("Adding new Client");
    this->resize(500, 300);

    connect(bCancel, &QPushButton::clicked, this, [this](){
        if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Cancel and exit?", QMessageBox::Yes | QMessageBox::No))
        {
            this->reject();
        }
    });
    connect(bOk, &QPushButton::clicked, this, [this](){
        if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Add client to database?\n(Currently not implemented)", QMessageBox::Yes | QMessageBox::No))
        {
            /*
             * Here the entered data must be read and used to create a new client object to be stored in the database
             * Probably emit a signal with the client object which is transferred to the database API
             */
        }
    });

}
