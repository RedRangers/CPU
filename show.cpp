#include"show.h"
#include<iostream>
#include<vector>
#include<stack>
#include<cassert>

#define CHECK
#undef CHECK

template< typename T >
void show_vector( std::vector<T>& a )
{
#ifdef CHECK
    assert( a );
#endif

    for( typename std::vector<T>::iterator it = a.begin(); it != a.end(); ++it )
        std::cout << *it << " ";
}

//!
//! \brief show_stack displays a container stack \param a
//! \typedef T type of elements in container \param a
//! \param a output container
//!
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
