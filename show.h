#ifndef SHOWVECTOR_H
#define SHOWVECTOR_H
#include<iostream>
#include<vector>
#include<stack>
#include<cassert>


#define CHECK
#undef CHECK

//!
//! \brief show_vector displays a container vector \param a
//! \typedef T type of elements in container \param a
//! \param a output container
//!
template< typename T >
void show_vector( std::vector<T>& a )
{
#ifdef CHECK
    assert( a );
#endif

    for( typename std::vector<T>::iterator it = a.begin(); it != a.end(); ++it )
        std::cout << *it << " ";
}

template< typename T >
void show_stack( std::stack<T> a )
{
#ifdef CHECK
    assert( a );
#endif

    while( !a.empty() )
    {
        std::cout << a.top() << " ";
        a.pop();
    }
}

#endif // SHOWVECTOR_H
