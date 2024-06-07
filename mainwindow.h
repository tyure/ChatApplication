#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registerform.h"
#include "chatclient.h"
#include "chatwindow.h"
#include "friendlistwindow.h"
#include "groupchatdialog.h"
#include "groupchatwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showRegistrationForm();
    void onRegistrationSuccessful(const QString &username);
    void onLoginSuccessful(const QString &username);
    void openChat();
    void createChat();
    void createGroupChat();
    void deleteChat();
    void openFriendList();

private:
    Ui::MainWindow *ui;
    RegisterForm *registerForm;
    ChatClient *chatClient;
    QString currentUsername;
    QList<ChatWindow*> openChatWindows;
    FriendListWindow *friendListWindow;
    GroupChatDialog *groupChatDialog;
    QList<GroupChatWindow*> openGroupChatWindows;

    void loadChats();
    void saveChats();
};

#endif // MAINWINDOW_H
