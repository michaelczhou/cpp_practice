/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_linuxshell;
    QLineEdit *lineEdit_commandline;
    QPushButton *pushButton_sendcmd;
    QPushButton *pushButton_exit;
    QWidget *tab_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(861, 506);
        MainWindow->setStyleSheet(QLatin1String("QWidget {\n"
"    background-color: rgb(0, 0, 0);\n"
"}\n"
" \n"
"QTabWidget::pane {\n"
"    position: absolute;\n"
"    border: 2px solid red;\n"
"}\n"
" \n"
"QTabWidget::tab-bar {\n"
"    alignment: center;\n"
"}\n"
" \n"
" \n"
"QTabBar::tab {\n"
"    color: red;\n"
"    background-color: black;\n"
"    border: 2px solid red;\n"
"    border-radius: 0px;\n"
"    padding: 4px;\n"
"    margin-left: 0.25em;\n"
"    margin-right: 0.25em;\n"
"}\n"
" \n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    color: white;\n"
"    background: red;\n"
"}\n"
" \n"
"QPushButton {\n"
"     /**font: bold 16pt;\n"
"     color: white ;\n"
" \n"
"     border-image: url(:/pushblueup.png);\n"
"     background-color: transparent;\n"
"     border-top: 3px transparent;\n"
"     border-bottom: 3px transparent;\n"
"     border-right: 10px transparent;\n"
"     border-left: 10px transparent;**/\n"
" }"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QLatin1String("QWidget{\n"
"    background-color: red;\n"
"}\n"
" \n"
"QTextBrowser{\n"
"    background-color: black;\n"
"    color: yellow;\n"
"}\n"
" \n"
"QLineEdit{\n"
"    background-color: white;\n"
"    color: black;\n"
"}\n"
" \n"
"QPushButton{\n"
"}\n"
" \n"
"QWebView{\n"
"    background-color: white;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser_linuxshell = new QTextBrowser(tab);
        textBrowser_linuxshell->setObjectName(QStringLiteral("textBrowser_linuxshell"));

        gridLayout->addWidget(textBrowser_linuxshell, 0, 0, 1, 2);

        lineEdit_commandline = new QLineEdit(tab);
        lineEdit_commandline->setObjectName(QStringLiteral("lineEdit_commandline"));

        gridLayout->addWidget(lineEdit_commandline, 1, 0, 1, 1);

        pushButton_sendcmd = new QPushButton(tab);
        pushButton_sendcmd->setObjectName(QStringLiteral("pushButton_sendcmd"));

        gridLayout->addWidget(pushButton_sendcmd, 1, 1, 1, 1);

        pushButton_exit = new QPushButton(tab);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        gridLayout->addWidget(pushButton_exit, 2, 0, 1, 2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lineEdit_commandline->setText(QApplication::translate("MainWindow", "date \342\200\223help", Q_NULLPTR));
        pushButton_sendcmd->setText(QApplication::translate("MainWindow", "Send CMD", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
