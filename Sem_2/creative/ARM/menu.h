#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"
#include "plan.h"
#include "ship.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_miningButton_clicked();

    void on_quitButton_clicked();

    void on_planButton_clicked();

    void on_shipButton_clicked();

private:
    Ui::Menu *ui;
    MainWindow *window;
    Plan *pwindow;
    Ship *swindow;
};

#endif // MENU_H
