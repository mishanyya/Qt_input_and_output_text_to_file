#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QApplication" //подключает класс для работы с QApplication, добавляется обязательно !!!

#include "QLineEdit" //подключает класс для работы с полем для ввода текста, добавляется при необходимости!
#include "QPushButton" //подключает класс для работы с кнопками, добавляется при необходимости!
#include "QLabel" //подключает класс для работы с полем для показа какой-либо информации, добавляется при необходимости!
#include "QFile" //подключает класс для работы с файлами, добавляется при необходимости!
#include "QDebug" //подключает класс для работы с выводом результата в консоль, добавляется при необходимости!


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(createFile())); //для создания файла при необходимости
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(addText())); //для ввода текста в файл
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(retrievetext())); //для вывода текста из файла
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(plusaddtext())); //для добавления текста в файл
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(deleteFile())); //для удаления файла
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFile()
{
//блок создания файла
//проверяем существует ли файл fortext.text
if(QFile::exists("fortext.txt"))
{
ui->label->setText("Файл существует");
}
else{
ui->label->setText("Файл НЕ существует");
QFile file("fortext.txt");//создаем объект для файла fortext.txt, но сам файл еще не создан
file.open(QIODevice::WriteOnly);//создаем файл fortext.txt в папке с исполняемым файлом!
}
}

void MainWindow::addText(){
//блок внесения текста в файл
if(QFile::exists("fortext.txt"))
{
QFile file("fortext.txt");//указываем файл fortext.txt
file.open(QIODevice::WriteOnly);//открываем файл fortext.txt, который расположен по умолчанию в папке с компилированными файлами!
//получаем содержимое поля QLineEdit
file.write(ui->lineEdit->text().toUtf8().data());
file.close();//закрываем файл
}
else{
ui->label->setText("Файл НЕ существует");
}
}

void MainWindow::retrievetext()
{
//блок получения информации из файла и вывода ее в поле
//проверяем существует ли файл fortext.text
if(QFile::exists("fortext.txt"))
{
QFile file("fortext.txt");//указываем файл fortext.txt
file.open(QIODevice::ReadOnly);//открываем файл только для чтения
ui->textEdit->setText(file.readAll());//выводим все содержимое файла
file.close();//закрываем файл
}
else{
ui->textEdit->setText("Файл НЕ существует");
}
}

void MainWindow::plusaddtext(){
    //блок добавления текста в файл
    //проверяем существует ли файл fortext.text, если существует покажем в элементе label_2 текст Файл существует, если нет, то Файл НЕ существует
    if(QFile::exists("fortext.txt"))
    {
        QFile file("fortext.txt");//указываем файл fortext.txt
        file.open(QFile::Append |QFile::Text);//открываем файл fortext.txt, для добавления текста в файл
        //получаем содержимое поля QLineEdit
        file.write(ui->lineEdit->text().toUtf8().data());
        file.close();//закрываем файл
    }
    else{
    ui->textEdit->setText("Файл НЕ существует");
    }
}

void MainWindow::deleteFile(){
    //блок удаления файла
    QFile file("fortext.txt");//указываем файл fortext.txt
    file.moveToTrash();//удаление файла в корзину
}
