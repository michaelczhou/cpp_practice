#include <iostream>
#include <thread>

using namespace std;

void output(int i)
{
    cout << i << endl;
}

int main()
{
    
    for (uint8_t i = 0; i < 4; i++)
    {
        thread t(output, i);
        //t.detach();   //表示该线程在后台允许，无需等待该线程完成，继续执行后面的语句。
        t.join();
    }
        
    getchar();
    return 0;
}
