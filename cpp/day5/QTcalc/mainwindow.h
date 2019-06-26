#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); //was: nullptr ->0
    ~MainWindow();

protected:
//    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    double num_first;
    bool userIsTypingSecondNumber = false;

private slots:
    void digits_numbers();
    void operations();
    void math_operations();
//    void on_pushButton_clear_clicked();
//    void on_pushButton_dot_clicked();
//    void on_pushButton_equal_clicked();
    void on_pushButton_clear_released();
    void on_pushButton_dot_released();
    void on_pushButton_equal_released();
};

#endif // MAINWINDOW_H
