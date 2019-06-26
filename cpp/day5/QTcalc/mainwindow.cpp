#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digits_numbers()));//clicked()
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_plus_minus, SIGNAL(released()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(released()), this, SLOT(operations()));

    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(math_operations()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(released()), this, SLOT(math_operations()));

//    ui->pushButton_plus->setChecked(true);
    ui->pushButton_plus->setCheckable(true);
//    ui->pushButton_minus->setChecked(true);
    ui->pushButton_minus->setCheckable(true);
//    ui->pushButton_divide->setChecked(true);
    ui->pushButton_divide->setCheckable(true);
//    ui->pushButton_mult->setChecked(true);
    ui->pushButton_mult->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::changeEvent(QEvent *e)
//{
//    QMainWindow::changeEvent(e);
//    switch (e->type()) {
//    case QEvent::LanguageChange:
//        ui->retranslateUi(this);
//        break;
//    default:
//        break;
//    }
//}

void MainWindow::digits_numbers()
{
//    qDebug << "test";
    QPushButton *  button = (QPushButton*)sender();
    double all_numbers;
    QString new_label;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() ||
            ui->pushButton_divide->isChecked() || ui->pushButton_mult->isChecked())
            && (!userIsTypingSecondNumber))
    {
        all_numbers = button->text().toDouble();
        userIsTypingSecondNumber = true;
        new_label = QString::number(all_numbers, 'g', 15);
    }
    else
    {
        if((ui->result_show->text().contains('.')) && (button->text() == "0")) {
           new_label = ui->result_show->text() + button->text();

        }
        else
        {
            all_numbers = (ui->result_show->text() + button->text()).toDouble();
            new_label = QString::number(all_numbers, 'g', 15);
        }
    }
    ui->result_show->setText(new_label);
}

//void MainWindow::on_pushButton_dot_clicked()
void MainWindow::on_pushButton_dot_released()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");

}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *) sender();
    double all_numbers;
    QString new_label;

    if (button->text() == "+/-") {
        all_numbers = ui->result_show->text().toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }  else if (button->text() == "%") {
        all_numbers = ui->result_show->text().toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->result_show->setText(new_label);
    }

}




//void MainWindow::on_pushButton_clear_clicked()
void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_mult->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->result_show->setText("0");
}



//void MainWindow::on_pushButton_equal_clicked()
void MainWindow::on_pushButton_equal_released()
{
    double labelNumber, num_second;
    QString new_label;
    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    } else if(ui->pushButton_minus->isChecked()) {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_divide->isChecked()) {
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_divide->setChecked(false);
    } else if(ui->pushButton_mult->isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}


void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->result_show->text().toDouble();
//    ui->result_show->setText("");
    button->setChecked(true);
}
