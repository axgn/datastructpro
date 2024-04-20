#ifndef __BDS_H__

#define __BDS_H__

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "SqStack_cpp.h"

constexpr char OP[10] = { '+', '-', '*', '/', '(', ')', '#' };

// ���������ȼ���
// 1 - ����(>, ���ȼ���)
// 2 - С��(<, ���ȼ���)
// 3 - ����(=, ���ȼ����)
// 0 - �գ����ڱ�Ǳ���Ϊ��
constexpr int precede[7][7] = {
    {1, 1, 2, 2, 2, 1, 1},
    {1, 1, 2, 2, 2, 1, 1},
    {1, 1, 1, 1, 2, 1, 1},
    {1, 1, 1, 1, 2, 1, 1},
    {2, 2, 2, 2, 2, 3, 0},
    {1, 1, 1, 1, 0, 1, 1},
    {2, 2, 2, 2, 2, 0, 3}
};

int In(char c, const char* op);

char Precede(char op, char c);

int Operate(int a, char theta, int  b);

int EvaluateExpression();


#endif