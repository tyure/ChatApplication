#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include "chatclient.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(ChatClient *chatClient, const QString &chatRoomName, QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void sendMessage();
    void receiveMessage(const Message &message);

private:
    Ui::ChatWindow *ui;
    ChatClient *chatClient;
    QString chatRoomName;

    void loadChatHistory();
};

#endif // CHATWINDOW_H
