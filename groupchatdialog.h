#ifndef GROUPCHATDIALOG_H
#define GROUPCHATDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include "chatclient.h"

namespace Ui {
class GroupChatDialog;
}

class GroupChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupChatDialog(ChatClient *chatClient, QWidget *parent = nullptr);
    ~GroupChatDialog();

    QStringList getSelectedUsers() const;
    QString getGroupName() const;

private slots:
    void on_addUserButton_clicked();
    void on_removeUserButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::GroupChatDialog *ui;
    ChatClient *chatClient;
};

#endif // GROUPCHATDIALOG_H
