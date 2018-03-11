#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "keyboard/keyboard.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_sendcmd_clicked();
    void open_keyboard_lineEdit();

private:
    Ui::MainWindow *ui;
    Keyboard *lineEditkeyboard;
};

#endif // MAINWINDOW_H
