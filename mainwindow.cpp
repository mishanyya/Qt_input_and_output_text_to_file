#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>//подключает класс для работы с QApplication, добавляется обязательно !!!

#include <QLineEdit> //подключает класс для работы с полем для ввода текста, добавляется при необходимости!
#include <QPushButton> //подключает класс для работы с кнопками, добавляется при необходимости!
#include <QLabel> //подключает класс для работы с полем для показа какой-либо информации, добавляется при необходимости!
#include <QFile> //подключает класс для работы с файлами, добавляется при необходимости!



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addText())); //для ввода текста в файл
}

MainWindow::~MainWindow()
{
    delete ui;
}

static float firstvalue;//первое введенное значение, пишется static, так как получает значение внутри другой функции

void MainWindow::addText()
{
QString b = QString::number(::firstvalue);//перевод из числового значения в текст, правда почему, я НЕ ПОНЯЛ ПОКА!
b= ui->lineEdit->text(); // получаем первое значение QLineEdit
//проверяем существует ли файл fortext.text, если существует покажем в элементе label_2 текст Файл существует, если нет, то Файл НЕ существует
if(QFile::exists("fortext.text"))
{
ui->lineEdit->setText("Файл существует");
}
else{
ui->lineEdit->setText("Файл НЕ существует");
}

}
