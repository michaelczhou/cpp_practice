#include "mainwindow.h"
#include <QApplication>


void Invoke(char* s);

////定义回调函数
//void PrintfText()
//{
//    printf("Hello World!\n");
//}
////定义实现回调函数的"调用函数"
//void CallPrintfText(void (*callfuct)())
//{
//    callfuct();
//}

定义带参回调函数
void PrintfText(char* s)
{
    printf(s);
}
定义实现带参回调函数的"调用函数"
void CallPrintfText(void (*callfuct)(char*),char* s)
{
    callfuct(s);
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


//    return a.exec();
    //printf("hello word!\n");
    //函数调用
    //Invoke("hello word!\n");
//    void (*fp)(char* s); //声明一个函数指针(fp)
//    fp = Invoke;         //将Invoke函数的入口地址赋值给fp
//    fp("hello word!\n");//函数指针fp是实现函数调用
    //CallPrintfText(PrintfText);
    CallPrintfText(PrintfText,"hello word!\n");
    return 0;
}

void Invoke(char* s)
{
    printf(s);
}
