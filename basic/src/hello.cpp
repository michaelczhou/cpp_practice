#include <iostream>
#include "Sales_item.h"

int main()
{
    int sum = 0,value = 0;
    while (std::cin >> value )
        sum += value;
    std::cout << "Sum = " << sum << std::endl;
    return 0;
}
