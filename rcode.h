#ifndef RCODE_H
#define RCODE_H
#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>

#include"showvector.h"

#define CHECK
#undef  CHECK

//!
//! \brief CodeFromFile reads out a code of skript from the file and writes down in a vector \param code
//! \param code vector with code of skript
//! \return TRUE if all is cool, FALSE otherwise
//!
bool code_of_skript( std::vector<int>& code )
{

//#ifndef CHECK
//    assert( code );
//#endif

    system( "notepad.exe code.txt" );
    std::fstream FCode( "code.txt" );

    if( !FCode.is_open() )
    {
        std::cout << "File code.txt not found" << std::endl;
        return false;
    }

    std::string line;

    while ( !FCode.eof() )
    {
        getline( FCode, line );
        try
        {
            code.push_back( std::stoi( line ) );
        }
        catch( ... )
        {
            if( line != "\n" && !line.empty() )
            {
                std::cout << "Error in file with Code " << line << std::endl;
                return true;
            }
        }
    }

#ifdef CHECK
    show_vector( code );
    std::cout << std::endl;
#endif

    FCode.close();
    return false;

}

#endif // RCODE_H
