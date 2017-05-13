#include<iostream>
#include<cassert>
#include<vector>
#include<stack>
#include"rcode.h"
#include"cpu.h"


int main()
{
    std::vector<int> Script;
    while( code_of_skript( Script ) );

    std::stack<double> Calc;

    size_t n = 0;
    std::cout << "Enter quantity of registers" << std::endl;
    std::cin >> n;

    std::vector<double> Registers( n );

    CPU( Script, Calc, Registers );

    for( size_t i = 0; i < Registers.size(); ++i )
        std::cout << Registers[ i ] << std::endl;

    return 0;
}
