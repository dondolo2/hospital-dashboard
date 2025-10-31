#include "patientpage.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

PatientPage::PatientPage(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    auto *title = new QLabel("🧍‍♂️ Patient Dashboard", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold;");

    auto *backButton = new QPushButton("Back", this);
    backButton->setStyleSheet("padding: 8px; font-size: 16px;");
    connect(backButton, &QPushButton::clicked, this, &PatientPage::backToLoginRequested);

    layout->addWidget(title);
    layout->addStretch();
    layout->addWidget(backButton, 0, Qt::AlignCenter);

    setLayout(layout);
}
