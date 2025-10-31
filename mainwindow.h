#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStackedWidget>
#include <QWidget>

class LoginWidget;
class AdminPage;
class HRPage;
class NursePage;
class DoctorPage;
class PatientPage;
class SupplyPage;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void handleLogin(const QString &role);

private:
    QStackedWidget *stack;
    LoginWidget *loginPage;
    AdminPage *adminPage;
    HRPage *hrPage;
    NursePage *nursePage;
    DoctorPage *doctorPage;
    PatientPage *patientPage;
    SupplyPage *supplyPage;
};

#endif // MAINWINDOW_H
