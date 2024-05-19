#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enterButton_clicked();

    void on_saveButton_clicked();

    void on_newButton_clicked();

    void on_clearButton_clicked();

    void on_quitButton_clicked();

    void on_delButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
