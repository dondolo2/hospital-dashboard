#include "mainwindow.h"
#include "loginwidget.h"
#include "adminpage.h"
#include "hrpage.h"
#include "nursepage.h"
#include "doctorpage.h"
#include "patientpage.h"
#include "supplypage.h"

#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    stack = new QStackedWidget(this);

    loginPage = new LoginWidget(this);
    adminPage = new AdminPage(this);
    hrPage = new HRPage(this);
    nursePage = new NursePage(this);
    doctorPage = new DoctorPage(this);
    patientPage = new PatientPage(this);
    supplyPage = new SupplyPage(this);

    stack->addWidget(loginPage);
    stack->addWidget(adminPage);
    stack->addWidget(hrPage);
    stack->addWidget(nursePage);
    stack->addWidget(doctorPage);
    stack->addWidget(patientPage);
    stack->addWidget(supplyPage);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stack);
    setLayout(layout);

    connect(loginPage, &LoginWidget::loginSuccessful, this, &MainWindow::handleLogin);

    // --- Connect all dashboards back to login ---
    connect(adminPage,  &AdminPage::backToLoginRequested,  this, [=]() { stack->setCurrentWidget(loginPage); });
    connect(hrPage,     &HRPage::backToLoginRequested,     this, [=]() { stack->setCurrentWidget(loginPage); });
    connect(nursePage,  &NursePage::backToLoginRequested,  this, [=]() { stack->setCurrentWidget(loginPage); });
    connect(doctorPage, &DoctorPage::backToLoginRequested, this, [=]() { stack->setCurrentWidget(loginPage); });
    connect(patientPage,&PatientPage::backToLoginRequested,this, [=]() { stack->setCurrentWidget(loginPage); });
    connect(supplyPage, &SupplyPage::backToLoginRequested, this, [=]() { stack->setCurrentWidget(loginPage); });

}

void MainWindow::handleLogin(const QString &role)
{
    if (role == "Admin")
        stack->setCurrentWidget(adminPage);
    else if (role == "HR")
        stack->setCurrentWidget(hrPage);
    else if (role == "Nurse")
        stack->setCurrentWidget(nursePage);
    else if (role == "Doctor")
        stack->setCurrentWidget(doctorPage);
    else if (role == "Patient")
        stack->setCurrentWidget(patientPage);
    else if (role == "Supply")
        stack->setCurrentWidget(supplyPage);
}

