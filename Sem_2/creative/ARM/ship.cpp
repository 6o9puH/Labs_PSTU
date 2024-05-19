#include "ship.h"
#include "ui_ship.h"
#include <QFile>
#include <QTextStream>

Ship::Ship(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ship)
{
    ui->setupUi(this);
}

Ship::~Ship()
{
    delete ui;
}

void Ship::on_quitButton_clicked()
{
    this->close();
}

void Ship::on_clearButton_clicked()
{
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"Отгрузка", "Поступление", "Накладные", "Вагоны", "Объем", "Заказчик"});

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        bool isEmpty = true;
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col)
        {
            if (ui->tableWidget->item(row, col) && !ui->tableWidget->item(row, col)->text().isEmpty())
            {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty)
        {
            ui->tableWidget->removeRow(row);
            row--;
        }
    }

    ui->label->setText("Пустые ряды удалены");
}

void Ship::on_enterButton_clicked()
{
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"Отгрузка", "Поступление", "Накладные", "Вагоны", "Объем", "Заказчик"});
    ui->tableWidget->setRowCount(0);

    QFile file("ship.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->label->setText("Файл не найден, создан новый");
        QFile file("ship.txt");
        file.open(QIODevice::WriteOnly);
        file.close();
        return;
    }

    int row = 0;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split("\t");

        ui->tableWidget->insertRow(row);
        ui->tableWidget->setColumnCount(fields.size());
        for (int col = 0; col < 6; ++col)
        {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(fields[col]));
        }

        ++row;
    }

    file.close();

    ui->label->setText("Таблица загружена");
}


void Ship::on_newButton_clicked()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    for (int col = 0; col < 6; ++col)
    {
        ui->tableWidget->setItem(row, col, new QTableWidgetItem(""));
    }
    ui->label->setText("");
}

void Ship::on_saveButton_clicked()
{
    on_clearButton_clicked();

    QFile file("ship.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&file);
    out.setCodec("UTF-8");
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        for (int col = 0; col < 6; ++col)
        {
            if(ui->tableWidget->item(row, col) != nullptr)
            {
                out << ui->tableWidget->item(row, col)->text();
            }
            if (col != ui->tableWidget->columnCount() - 1){out << "\t";}
        }
        if (row != ui->tableWidget->rowCount() - 1){out << '\n';}
    }
    file.close();

    ui->label->setText("Таблица сохранена");
}

void Ship::on_delButton_clicked()
{
    int row = ui->lineEdit->text().toInt();
    if (row > 0 && row <= ui->tableWidget->rowCount())
    {
        ui->tableWidget->removeRow(row - 1);
        ui->label->setText("");
    }
    else
    {
        ui->label->setText("Такого ряда нет");
    }
    ui->lineEdit->clear();
}
