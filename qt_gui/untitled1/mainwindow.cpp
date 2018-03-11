#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lineEditkeyboard = new Keyboard();
    connect( ui->lineEdit_commandline ,SIGNAL(selectionChanged()),this ,SLOT(open_keyboard_lineEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    qApp->quit();
}

void MainWindow::on_pushButton_sendcmd_clicked()
{
    QString LinuxTexttoSend = ui->lineEdit_commandline->text();
    // QProcess used to binaries in /usr/bin
    QProcess process;
    // Merge Channels so the output of binaries can be seen
    process.setProcessChannelMode(QProcess::MergedChannels);
    // Start whatever command is in LinuxTexttoSend
    process.start(LinuxTexttoSend, QIODevice::ReadWrite);
    // Run the command and loop the output into a QByteArray
    QByteArray data;
    while(process.waitForReadyRead())
    data.append(process.readAll());
    ui->textBrowser_linuxshell->setText(data.data());
}

void MainWindow::open_keyboard_lineEdit()
{
    QLineEdit *line = (QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
}
