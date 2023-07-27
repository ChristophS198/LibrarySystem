#include <QPushButton>
#include <QCommonStyle>

#include "mediamanagementwidget.h"

MediaManagementWidget::MediaManagementWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton *backButton = new QPushButton(this);
    QCommonStyle style;
    backButton->setIcon(style.standardIcon(QStyle::SP_ArrowBack));

    connect(backButton, &QPushButton::clicked, this, [this](){emit goBackToMainView(); });
}
