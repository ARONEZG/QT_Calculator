#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , obj(new Calculator())
{

    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_multi, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_left_b, SIGNAL(clicked()), this, SLOT(DigitsNum()));
    connect(ui->pushButton_right_b, SIGNAL(clicked()), this, SLOT(DigitsNum()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(WriteDot()));

    connect(ui->pushButton_delete, SIGNAL(clicked()), this, SLOT(DeleteExpr()));

    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(Calculate()));

}

MainWindow::~MainWindow()
{
    obj->WriteHistory();
    delete ui;
    delete obj;
}

void MainWindow::DigitsNum() {
    QPushButton* button = (QPushButton*)sender();
    ui->result->setText(ui->result->text() + button->text());
}

void MainWindow::DeleteExpr() {
    ui->result->setText("");
}

void MainWindow::WriteDot() {
    if (!(ui->result->text().contains('.'))) {
        ui->result->setText(ui->result->text() + ".");
    }
}

void MainWindow::Calculate() {
    try {
        ExpressionConverter expr(ui->result->text().toStdString());
        ui->result->setText(QString::fromStdString(std::to_string(obj->Calculate(expr))));
    } catch(const std::exception& err) {
        ui->result->setText("Некорректное выражение");
    }
}
