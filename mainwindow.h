#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void createFile();// это созданный нами слот для проверки существования файла fortext.text и его создания при необходимости после нажатия кнопки QPushButton
    void addText(); // это созданный нами слот для внесения текста из поля QLineEdit в какой-либо текстовый файл после нажатия кнопки QPushButton
    void retrievetext();//это созданный нами слот для вывода текста из фала после нажатия кнопки QPushButton
};
#endif // MAINWINDOW_H
