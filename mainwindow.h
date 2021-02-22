#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QMainWindow"

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
    void createFile();// это созданный нами слот для проверки существования файла fortext.text и его создания
    void addText(); // это созданный нами слот для внесения текста из поля QLineEdit в текстовый файл
    void retrievetext();//это созданный нами слот для вывода текста из файла
    void plusaddtext();// это созданный нами слот для добавления текста из поля QLineEdit в текстовый файл
    void deleteFile();//это созданный нами слот для удаления файла

};
#endif // MAINWINDOW_H
