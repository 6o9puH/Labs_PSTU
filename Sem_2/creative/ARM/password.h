#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include <QMainWindow>
#include "menu.h"

namespace Ui {
class Password;
}

class Password : public QDialog
{
    Q_OBJECT

public:
    explicit Password(QWidget *parent = nullptr);
    ~Password();

private slots:
    void on_enterButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::Password *ui;
    Menu *window;
};

#endif // PASSWORD_H
