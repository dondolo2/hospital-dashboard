#include "loginwidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
{
    auto *layout = new QVBoxLayout(this);

    auto *title = new QLabel("🏥 Hospital Dashboard Login", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold;");

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Enter username...");

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Password");
    passwordEdit->setEchoMode(QLineEdit::Password);

    roleSelector = new QComboBox(this);
    roleSelector->addItems({"Admin", "HR", "Nurse", "Doctor", "Patient", "Supply"});

    loginButton = new QPushButton("Login", this);

    layout->addWidget(title);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordEdit);
    layout->addWidget(roleSelector);
    layout->addWidget(loginButton);
    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWidget::onLoginClicked);
}

void LoginWidget::onLoginClicked()
{
    QString username = usernameInput->text().trimmed();
    QString password = passwordEdit->text().trimmed();
    QString role = roleSelector->currentText();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Please enter both username and password.");
        return;
    }

    if (verifyCredentials(role, username, password)) {
        emit loginSuccessful(role);
    } else {
        QMessageBox::critical(this, "Login Failed", "Invalid username or password for this role.");
    }
}

bool LoginWidget::verifyCredentials(const QString &role, const QString &username, const QString &password)
{
    // 🔒 Hardcoded credentials (temporary)
    static const QMap<QString, QPair<QString, QString>> credentials = {
        {"Admin",   {"admin",   "admin123"}},
        {"HR",      {"hruser",  "hrpass"}},
        {"Doctor",  {"druser",  "drpass"}},
        {"Nurse",   {"nurse1",  "nurse123"}},
        {"Patient", {"patient", "pat123"}},
        {"Supply",  {"supply",  "sup123"}}
    };

    if (!credentials.contains(role))
        return false;

    QPair<QString, QString> creds = credentials.value(role);
    return (username == creds.first && password == creds.second);
}
