#ifndef FRIENDLISTWINDOW_H
#define FRIENDLISTWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include "chatclient.h"

namespace Ui {
class FriendListWindow;
}

class FriendListWindow : public QDialog {
    Q_OBJECT

public:
    explicit FriendListWindow(ChatClient *chatClient, QWidget *parent = nullptr);
    ~FriendListWindow();

private slots:
    void addFriend();
    void removeFriend();

private:
    Ui::FriendListWindow *ui;
    ChatClient *chatClient;
    void loadFriends();
    void saveFriends();
};

#endif // FRIENDLISTWINDOW_H
