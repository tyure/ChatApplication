#include "chatapplication.h"
#include "ui_chatapplication.h"

ChatApplication::ChatApplication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChatApplication)
{
    ui->setupUi(this);
}

ChatApplication::~ChatApplication()
{
    delete ui;
}
