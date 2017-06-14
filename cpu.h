#ifndef CPU_H
#define CPU_H
#include<stack>
#include<vector>

//!
//! \brief CPU executes the script
//! \param code script code
//! \param Calc result
//! \param Registers container with values ​​stored in memory CPU
//!
void CPU( std::vector<int>& code, std::stack<double>& Calc, std::vector<double>& Registers  );

#endif // CPU_H
