#include "plan.h"
#include "ui_plan.h"
#include <QFile>
#include <QTextStream>

Plan::Plan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plan)
{
    ui->setupUi(this);
}

Plan::~Plan()
{
    delete ui;
}

void Plan::on_quitButton_clicked()
{
    this->close();
}

void Plan::on_clearButton_clicked()
{
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Участок", "На месяц", "На сутки"});

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

void Plan::on_enterButton_clicked()
{
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Участок", "На месяц", "На сутки"});
    ui->tableWidget->setRowCount(0);

    QFile file("plan.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->label->setText("Файл не найден, создан новый");
        QFile file("plan.txt");
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
        for (int col = 0; col < 3; ++col)
        {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(fields[col]));
        }

        ++row;
    }

    file.close();

    ui->label->setText("Таблица загружена");
}


void Plan::on_newButton_clicked()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    for (int col = 0; col < 3; ++col)
    {
        ui->tableWidget->setItem(row, col, new QTableWidgetItem(""));
    }
    ui->label->setText("");
}

void Plan::on_saveButton_clicked()
{
    on_clearButton_clicked();

    QFile file("plan.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&file);
    out.setCodec("UTF-8");
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        for (int col = 0; col < 3; ++col)
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

void Plan::on_delButton_clicked()
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

void Plan::on_count31Button_clicked()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        int count = ui->tableWidget->item(i,1)->text().toInt()/31;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(count));
        ui->tableWidget->setItem(i, 2, item);
    }
}


void Plan::on_count30Button_clicked()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        int count = ui->tableWidget->item(i,1)->text().toInt()/30;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(count));
        ui->tableWidget->setItem(i, 2, item);
    }
}


void Plan::on_count29Button_clicked()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        int count = ui->tableWidget->item(i,1)->text().toInt()/29;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(count));
        ui->tableWidget->setItem(i, 2, item);
    }
}


void Plan::on_count28Button_clicked()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        int count = ui->tableWidget->item(i,1)->text().toInt()/28;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(count));
        ui->tableWidget->setItem(i, 2, item);
    }
}

