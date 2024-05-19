#ifndef SHIP_H
#define SHIP_H

#include <QDialog>

namespace Ui {
class Ship;
}

class Ship : public QDialog
{
    Q_OBJECT

public:
    explicit Ship(QWidget *parent = nullptr);
    ~Ship();

private slots:
    void on_quitButton_clicked();

    void on_enterButton_clicked();

    void on_saveButton_clicked();

    void on_newButton_clicked();

    void on_clearButton_clicked();

    void on_delButton_clicked();
private:
    Ui::Ship *ui;
};

#endif // SHIP_H
