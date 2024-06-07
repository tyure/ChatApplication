#include "registerform.h"
#include "ui_registerform.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

RegisterForm::RegisterForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterForm) {
    ui->setupUi(this);
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterForm::onRegisterButtonClicked);
    connect(ui->loginButton, &QPushButton::clicked, this, &RegisterForm::onLoginButtonClicked);
}

RegisterForm::~RegisterForm() {
    delete ui;
}

bool RegisterForm::isUserExists(const QString &username) {
    QFile file("users/registered_users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line == username) {
                return true;
            }
        }
        file.close();
    }
    return false;
}

void RegisterForm::onRegisterButtonClicked() {
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Registration", "Please fill in all fields.");
        return;
    }

    if (isUserExists(username)) {
        QMessageBox::warning(this, "Registration", "User already exists.");
        return;
    }

    QFile file("users/registered_users.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << "\n";
        file.close();
    }

    QFile userFile("users/" + username + ".txt");
    if (userFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&userFile);
        out << username << "|" << password << "\n";
        userFile.close();
    }

    emit registrationSuccessful(username);
    accept();
}

void RegisterForm::onLoginButtonClicked() {
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Please fill in all fields.");
        return;
    }

    QFile file("users/registered_users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line == username) {
                QFile userFile("users/" + username + ".txt");
                if (userFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream userIn(&userFile);
                    QString userLine = userIn.readLine();
                    QStringList parts = userLine.split("|");
                    if (parts.size() == 2 && parts[0] == username && parts[1] == password) {
                        file.close();
                        userFile.close();
                        emit loginSuccessful(username);
                        accept();
                        return;
                    }
                    userFile.close();
                }
            }
        }
        file.close();
    }

    QMessageBox::warning(this, "Login", "Invalid username or password.");
}
