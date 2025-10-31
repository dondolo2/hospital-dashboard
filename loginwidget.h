#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

class QLineEdit;
class QComboBox;
class QPushButton;

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);

signals:
    void loginSuccessful(const QString &role);

private slots:
    void onLoginClicked();

private:
    QLineEdit *usernameInput;
    QLineEdit *passwordEdit;
    QComboBox *roleSelector;
    QPushButton *loginButton;

    bool verifyCredentials(const QString &role, const QString &username, const QString &password);
};

#endif // LOGINWIDGET_H
