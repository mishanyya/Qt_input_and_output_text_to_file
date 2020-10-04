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
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(createFile())); //для создания файла при необходимости
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(addText())); //для ввода текста в файл
}

MainWindow::~MainWindow()
{
    delete ui;
}

static float firstvalue;//первое введенное значение, пишется static, так как получает значение внутри другой функции

void MainWindow::createFile()
{
//блок создания файла
//проверяем существует ли файл fortext.text, если существует покажем в элементе label_2 текст Файл существует, если нет, то Файл НЕ существует
if(QFile::exists("fortext.txt"))
{
ui->label->setText("Файл существует");
}
else{
ui->label->setText("Файл НЕ существует");
QFile file("fortext.txt");//создаем файл fortext.text, но он не создан
file.open(QIODevice::WriteOnly);//создаем файл fortext.text, после второго нажатия кнопки вроде создался, но не понятно в каком месте
/*/home/mishanyya/build-addinfoinfile-Desktop_Qt_5_14_2_GCC_64bit-Debug/fortext.text он создался в папке с исполняемым файлом!*/
}
}


void MainWindow::addText(){
//блок внесения текста в файл
        if(QFile::exists("fortext.txt"))
        {
            QString b = QString::number(::firstvalue);//перевод из числового значения в текст, правда почему, я НЕ ПОНЯЛ ПОКА!
            b=ui->lineEdit->text(); // получаем первое значение QLineEdit
        ui->label->setText("Файл существует");
        QFile file("fortext.txt");//указываем файл fortext.txt
        file.open(QIODevice::WriteOnly);//открываем файл fortext.text, который расположен по умолчанию по указанному адресу
        /*/home/mishanyya/build-addinfoinfile-Desktop_Qt_5_14_2_GCC_64bit-Debug/fortext.text он создался в папке с исполняемым файлом!*/

        //file.open(QIODevice::ReadWrite)
        //file.write("b");//записываем само значение b
        //int bsize=sizeof(b);//определяем размер переменной
        //ui->label->setNum(bsize);//показало почему-то 8 при различном количестве вводимых символов

        //переводим значение переменнуой b из типа QString в char
        //1 способ
                        //const char* bb = b.toStdString().c_str();
                        //работает только с латинским или только с кириллическим шрифтом
                        //Совместное использование может перекодировать все символы в файле или вообще оставить файл пустым
        //2 способ
                        //char* bb = b.toUtf8().data();//переводим из QString в char для возможности записи в файл, это работает и с латинским и с кириллическим алфавитами
                        //работает только с латинским или только с кириллическим шрифтом
                        //Совместное использование может перекодировать все символы в файле или вообще оставить файл пустым

          //3 способ
                        char* bb = b.toLocal8Bit().data();//переводим из QString в char для возможности записи в файл, это работает и с латинским и с кириллическим алфавитами
                        //работает только с латинским или только с кириллическим шрифтом
                        //Совместное использование может перекодировать все символы в файле или вообще оставить файл пустым




        file.write(bb);   // записываем значение из переменной b

        file.close();//закрываем файл
        }
        else{
        ui->label->setText("Файл НЕ существует");
        QFile file("fortext.txt");//создаем файл fortext.text, но он не создан
        file.open(QIODevice::WriteOnly);//создаем файл fortext.text, после второго нажатия кнопки вроде создался, но не понятно в каком месте
        /*/home/mishanyya/build-addinfoinfile-Desktop_Qt_5_14_2_GCC_64bit-Debug/fortext.text он создался в папке с исполняемым файлом!*/
        }
}
