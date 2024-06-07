#ifndef CHATAPPLICATION_H
#define CHATAPPLICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ChatApplication;
}
QT_END_NAMESPACE

class ChatApplication : public QMainWindow
{
    Q_OBJECT

public:
    ChatApplication(QWidget *parent = nullptr);
    ~ChatApplication();

private:
    Ui::ChatApplication *ui;
};
#endif // CHATAPPLICATION_H
