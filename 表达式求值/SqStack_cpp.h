#ifndef __SQSTACK_CPP_H__

#define __SQSTACK_CPP_H__


#include <stdlib.h>
#include <stdio.h>

#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OK 1
#define EQUAL 1
#define MY_OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;

typedef char SElemType;

typedef int SElemType_int;

typedef struct
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

typedef struct
{
	SElemType_int* base;
	SElemType_int* top;
	int stacksize;
}SqStack_int;


Status InitStack(SqStack& S);

Status DestroyStack(SqStack& S);

Status ClearStack(SqStack& S);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

SElemType GetTop(SqStack S);

Status Push(SqStack& S, SElemType e);

Status Pop(SqStack& S, SElemType& e);

void StackTraverse(SqStack S);

Status InitStack(SqStack_int& S);

Status DestroyStack(SqStack_int& S);

Status ClearStack(SqStack_int& S);

Status StackEmpty(SqStack_int S);

int StackLength(SqStack_int S);

SElemType_int GetTop(SqStack_int S);

Status Push(SqStack_int& S, SElemType_int e);

Status Pop(SqStack_int& S, SElemType_int& e);

void StackTraverse(SqStack_int S);

#endif