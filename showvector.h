#ifndef SHOWVECTOR_H
#define SHOWVECTOR_H
#include<iostream>
#include<vector>
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

#endif // SHOWVECTOR_H
