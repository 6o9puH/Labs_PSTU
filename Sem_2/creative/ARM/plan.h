#ifndef PLAN_H
#define PLAN_H

#include <QDialog>

namespace Ui {
class Plan;
}

class Plan : public QDialog
{
    Q_OBJECT

public:
    explicit Plan(QWidget *parent = nullptr);
    ~Plan();

private slots:
    void on_quitButton_clicked();

    void on_enterButton_clicked();

    void on_saveButton_clicked();

    void on_newButton_clicked();

    void on_clearButton_clicked();

    void on_delButton_clicked();

    void on_count31Button_clicked();

    void on_count30Button_clicked();

    void on_count29Button_clicked();

    void on_count28Button_clicked();

private:
    Ui::Plan *ui;
};

#endif // PLAN_H
