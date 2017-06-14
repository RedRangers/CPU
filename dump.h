#ifndef DUMP_H
#define DUMP_H
#include<stack>
#include<vector>
#include"show.h"

void dump( std::stack<double> Stack, std::vector<double> Reg, std::vector<int> Code, int i )
{

    std::cout << "\ni = " << i << " code = " << Code [ i ] << std::endl;
    std::cout << "\nRegistrs: ";

    show_vector( Reg );
    std::cout << std::endl;

    std::cout << "Stack: ";
    while ( !Stack.empty() ) {
        std::cout << Stack.top() << " ";
        Stack.pop();
    }
    std::cout << std::endl;
}
#endif // DUMP_H
