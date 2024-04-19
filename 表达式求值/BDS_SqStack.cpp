#include"SqStack_cpp.h"


Status InitStack(SqStack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack& S)
{
	if (S.base) {
		free(S.base);
		return OK;
	}
	else {
		return ERROR;
	}
}

Status ClearStack(SqStack& S)
{
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack S)
{
	if (S.top == S.base) return TRUE;
	else return FALSE;
}

int StackLength(SqStack S)
{
	return S.top - S.base;
}

SElemType GetTop(SqStack S)
{
	if (S.top == S.base) exit(OVERFLOW);
	return *(S.top - 1);
}

Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top++) = e;
	return OK;
}

Status Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

void StackTraverse(SqStack S) {
	if (S.top == S.base) { return; }
	else {
		--S.top;
		StackTraverse(S);
		printf("%c ", *S.top);
		return;
	}
}

Status InitStack(SqStack_int& S)
{
	S.base = (SElemType_int*)malloc(STACK_INIT_SIZE * sizeof(SElemType_int));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack_int& S)
{
	if (S.base) {
		free(S.base);
		return OK;
	}
	else {
		return ERROR;
	}
}

Status ClearStack(SqStack_int& S)
{
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack_int S)
{
	if (S.top == S.base) return TRUE;
	else return FALSE;
}

int StackLength(SqStack_int S)
{
	return S.top - S.base;
}

SElemType_int GetTop(SqStack_int S)
{
	if (S.top == S.base) exit(OVERFLOW);
	return *(S.top - 1);
}

Status Push(SqStack_int& S, SElemType_int e)
{
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType_int*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType_int));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top++) = e;
	return OK;
}

Status Pop(SqStack_int& S, SElemType_int& e)
{
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

void StackTraverse(SqStack_int S) {
	if (S.top == S.base) { return; }
	else {
		--S.top;
		StackTraverse(S);
		printf("%c ", *S.top);
		return;
	}
}