#ifndef KEY_H
#define KEY_H
#include<iostream>
#include<map>

using std::string;

const int CHIPER_LINK  = -1;

const string STR_END  = "end";
const int CODE_END    = 0;

const string STR_PUSH = "push";
const int CODE_PUSH   = 1;

const string STR_POP  = "pop";
const int CODE_POP    = 2;

const string STR_ADD  = "add";
const int CODE_ADD    = 3;

const string STR_SUB  = "sub";
const int CODE_SUB    = 4;

const string STR_DIV  = "div";
const int CODE_DIV    = 5;

const string STR_MULT = "mult";
const int CODE_MULT   = 6;

const string STR_POW  = "pow";
const int CODE_POW    = 7;

const string STR_JMP  = "jmp";
const int CODE_JMP    = 8;

const string STR_CALL  = "call";
const int CODE_CALL    = 9;

const string STR_RET  = "ret";
const int CODE_RET    = 10;

const string STR_JE   = "je";
const int CODE_JE     = 11;

const string STR_JA   = "ja";
const int CODE_JA     = 12;

const string STR_JAE  = "jae";
const int CODE_JAE    = 13;

const string STR_JB   = "jb";
const int CODE_JB     = 14;

const string STR_JBE  = "jbe";
const int CODE_JBE    = 15;

const string STR_JNE  = "jne";
const int CODE_JNE    = 16;

const string STR_X0   = "x0";
const int CODE_X0     = 17;

const string STR_X1   = "x1";
const int CODE_X1     = 18;

const string STR_X2   = "x2";
const int CODE_X2     = 19;

const int MAX_CODE    = 19;
#endif // KEY_H
