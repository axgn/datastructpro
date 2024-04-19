#include"BDS.h"

int In(char c, const char* op)
{
	int i = 0;
	while (i < 7)
		if (c == op[i++]) return 1;
	return 0;
}

char Precede(char op, char c)
{
	int pos_op;
	int pos_c;
	int i;
	for (i = 0; i < 7; i++) {
		if (op == OP[i]) pos_op = i;
		if (c == OP[i]) pos_c = i;
	}
	switch (precede[pos_op][pos_c]) {
	case 1:  return '>';
	case 2:  return '<';
	case 3:  return '=';
	default: return 0;
	}
}

int Operate(int a, char theta, int b)
{
	switch (theta) {
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	default:return 0;
	}
}

int EvaluateExpression()
{
	SqStack_int OPND;
	SqStack OPTR;
	char c,  theta;
	int a, b,x;
	InitStack(OPTR);  Push(OPTR, '#');
	InitStack(OPND);
	c = getchar(); 
	while (c != '#' || GetTop(OPTR) != '#') {
		if (!In(c, OP)) {
			bool fir = true;
			int num = c - '0';
			while (c >= '0' && c <= '9')
			{
				if (fir)
				{
					fir = false;
				}
				else {
					num =c -'0'+ num * 10;
				}
				c = getchar();
			}
			Push(OPND, num);
		}
		else {
			switch (Precede(GetTop(OPTR), c)) {
			case '<':
				Push(OPTR, c);
				c = getchar();  
				break;
			case '=':
				Pop(OPND, x);
				c = getchar(); 
				break;
			case '>':
				Pop(OPTR, theta);
				Pop(OPND, b); 
				Pop(OPND, a);
				if (theta=='/'&&b==0)
				{
					return ERROR;
				}
				Push(OPND, Operate(a, theta, b));
				break;
			}
		}
	}
	x = GetTop(OPND);
	DestroyStack(OPTR);
	DestroyStack(OPND);
	return x;
}
