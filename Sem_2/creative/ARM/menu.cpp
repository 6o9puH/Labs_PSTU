#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_miningButton_clicked()
{
    window = new MainWindow(this);
    window->show();
}

void Menu::on_quitButton_clicked()
{
    exit(0);
}


void Menu::on_planButton_clicked()
{
    pwindow = new Plan(this);
    pwindow->show();
}


void Menu::on_shipButton_clicked()
{
    swindow = new Ship(this);
    swindow->show();
}

