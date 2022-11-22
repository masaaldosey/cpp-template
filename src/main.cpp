#include<iostream>
#include "Algorithm.h"

int main()
{
    int number_1 = 0;
    int number_2 = 0;

    std::cout << "THIS IS SIMPLE PROGRAM TO ADD TWO NUMBERS" << std::endl;

    std::cout << "Enter the first number : " << std::endl;
    std::cin >> number_1;

    std::cout << "Enter the second number : " << std::endl;
    std::cin >> number_2;

    int result = AddTwoNumbers(number_1, number_2);
    std::cout << number_1 << " + " << number_2 << " = " << result << std::endl;

    return 0;
}
