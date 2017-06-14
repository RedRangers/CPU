#ifndef CPU_H
#define CPU_H
#include<iostream>
#include<cassert>
#include<stack>
#include<vector>
#include<cmath>
#include"key.h"
#include"dump.h"

#define CHECK

const double EPSILON = 1e-6;

//!
//! \brief CPU executes the script
//! \param code script code
//! \param Calc result
//! \param Registers container with values ​​stored in memory CPU
//!
void CPU( std::vector<int>& code, std::stack<double>& Calc, std::vector<double>& Registers  )
{
    size_t i = 0;
    std::stack<int> Ret;
    double x(0), y(0);

    while ( i < code.size() )
    {
#ifdef CHECK
        std::cout << "\ni:" << i ;
        std::cout << "\nReg\n";
        show_vector( Registers );

        std::cout << "\nStack\n";
        show_stack( Calc );
        std::cin.get();
#endif
        switch ( code[ i ] )
        {
            case CODE_END:
                return;

            case CODE_PUSH:
                ++i;
                if( ( code[ i ] - CODE_X0 ) >= 0 &&  ( code[ i ] - CODE_X0 ) <= Registers.size() )
                {
                    if( !std::isfinite(  Registers[ code[ i ] - CODE_X0 ] ) )
                        assert( !"Error into Registers" ) ;
                    Calc.push( Registers[ code[ i ] - CODE_X0 ] );
                }
                else
                    Calc.push( code[ i ] );

                ++i;
            break;

            case CODE_POP:
                ++i;

                if( code[ i ] - CODE_X0 >= 0 && code[ i ] - CODE_X0 <= Registers.size() )
                {
                    Registers[ code[ i ] - CODE_X0 ] = Calc.top();
                    Calc.pop();
                }

                ++i;
            break;

            case CODE_ADD:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();
                Calc.push( x + y );

                ++i;
            break;

            case CODE_SUB:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();
                Calc.push( y - x );
                ++i;
            break;

            case CODE_DIV:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();

                assert( fabs( x ) < EPSILON );

                Calc.push( y/x );
                ++i;
            break;

            case CODE_MULT:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();
                Calc.push( x*y );
                ++i;
            break;

            case CODE_POW:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();
                Calc.push( pow( x, y ) );
                ++i;
            break;

            case CODE_JMP:
                ++i;
                i = code[ i ];
            break;

            case CODE_CALL:
                Ret.push( code[ ++i ] );
                ++i;
            break;

            case CODE_RET:
                i = Ret.top();
                Ret.pop();
            break;

            case CODE_JE:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();

                ++i;

                if( x == y )
                    i = code[ i ];
                else
                    ++i;
            break;

            case CODE_JA:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();

                ++i;

                if( x < y )
                    i = code[ i ];
                else
                    ++i;
            break;

            case CODE_JAE:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();

                ++i;

                if( x <= y )
                    i = code[ i ];
                else
                    ++i;
            break;

            case CODE_JB:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();

                ++i;

                if( x > y )
                    i = code[ i ];
                else
                    ++i;

            break;

            case CODE_JBE:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();
                ++i;

                if( x >= y )
                    i = code[ i ];
                else
                    ++i;

            break;

            case CODE_JNE:
                assert( Calc.size() >= 2 );

                x = Calc.top();
                Calc.pop();
                y = Calc.top();
                Calc.pop();
                ++i;

                if( x != y )
                    i = code[ i ];
                else
                    ++i;
            break;

            default:
                std::cout << "Command " << code[ i ] << " line " << i;
                assert( !"Incorrect\n" );

        }
#ifdef CHECK 
        std::cout << "\ni:" << i ;
        std::cout << "\nReg\n";
        show_vector( Registers );

        std::cout << "\nStack\n";
        show_stack( Calc );
        std::cin.get();
#endif
     }
}
#endif // CPU_H
