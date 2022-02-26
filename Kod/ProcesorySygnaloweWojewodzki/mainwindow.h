#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"Efekty.hpp"

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
    void on_pushButton_WCZYTAJ_clicked();

    void on_pushButton_ZAPISZ_clicked();

    void on_pushButton_AMPLITUDA_clicked();

    void on_pushButton_INWERSJA_clicked();

    void on_pushButton_WYCISZ_clicked();

    void on_pushButton_ZWIEKSZ_GLOSNOSC_clicked();

    void on_pushButton_ZMNIEJSZ_GLOSNOSC_clicked();

    void on_pushButton_Export_Do_Txt_clicked();

  //  void on_pushButton_ECHO_clicked();

    void on_pushButton_ECHO_clicked();

private:
    Ui::MainWindow *ui;
    EFEKTY efekty;
};
#endif // MAINWINDOW_H
