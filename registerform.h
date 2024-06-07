#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QDialog>

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QDialog {
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

signals:
    void registrationSuccessful(const QString &username);
    void loginSuccessful(const QString &username);

private slots:
    void onRegisterButtonClicked();
    void onLoginButtonClicked();

private:
    Ui::RegisterForm *ui;
    bool isUserExists(const QString &username);
};

#endif // REGISTERFORM_H
