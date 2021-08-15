#include "equal_zero.hpp"
#include "add.hpp"
#include "divide.hpp"

int main(int argc, char** argv)
{
    equal_zero::test();
    
    add::add_test();
    add::add_test_1();

    divide::divide_test_1();
    divide::divide_test_2();

    return 0;
}
