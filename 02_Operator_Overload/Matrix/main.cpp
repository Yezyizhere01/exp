#include <iostream>
#include "Matrix.h"

int main()
{
    std::cout << "enter matrix:";
    matrix m0;
    std::cin >> m0;
    std::cout << "display matrix:";
    std::cout << m0 << std::endl;
    matrix m1;
    matrix m2(1.1,2.2,3.3,4.4);
    std::cout << "every test will be done using m1 and m2." << std::endl;
    std::cout << "test initialization:" << m1 << std::endl;
    std::cout << "test + operator:" << m1 + m2 << std::endl;
    std::cout << "test - operator:" << m1 - m2 << std::endl;
    std::cout << "test * operator:" << m1 * m2 << std::endl;
    std::cout << "test += operator:" << (m1 += m2) << std::endl;
    std::cout << "test -= operator:" << (m1 -= m2) << std::endl;
    std::cout << "test *= operator:" << (m1 *= m2) << std::endl;
    std::cout << "test * operator with scalar:" << m1 * 2.0 << std::endl;
    std::cout << "test *= operator with scalar:" << (m1 *= 2.0) << std::endl;
    std::cout << "test == and != operator with \'m2 == m2\' and \'m1 != m2\':" << std::endl;
    if(m2 == m2)
        std::cout << "m2 is equal to m2" << std::endl;
    if(m1 != m2)
        std::cout << "m1 is not equal to m2" << std::endl;
    return 0;
}