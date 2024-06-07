#ifndef GROUPCHATWINDOW_H
#define GROUPCHATWINDOW_H

#include <QDialog>
#include "chatclient.h"

namespace Ui {
class GroupChatWindow;
}

class GroupChatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GroupChatWindow(ChatClient *chatClient, const QString &groupName, QWidget *parent = nullptr);
    ~GroupChatWindow();

private slots:
    void sendMessage();
    void receiveMessage(const Message &message);
    void addUser();

private:
    Ui::GroupChatWindow *ui;
    ChatClient *chatClient;
    QString groupName;

    void loadChatHistory();
};

#endif // GROUPCHATWINDOW_H
