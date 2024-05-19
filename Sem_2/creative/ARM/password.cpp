#include "password.h"
#include "ui_password.h"

Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{
    ui->setupUi(this);
}

Password::~Password()
{
    delete ui;
}

void Password::on_enterButton_clicked()
{
    QString line = ui->passwordLine->text();
    if (line == "password")
    {
        this->close();
        window = new Menu(this);
        window->show();
    }
    else
    {
        ui->label_2->setText("Неверно");
    }
}


void Password::on_quitButton_clicked()
{
    exit(0);
}

