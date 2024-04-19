#include"BDS.h";

int main()
{
	char i;
	printf("\n\n\n\nOnly within 0..9 evaluation,input a expression end with symbol #:\n");
	i = EvaluateExpression(); // 7+(3+8)*5# 
	printf("\nThis expression's result is:   ");
	printf("%d\n\n\n\n", i - '0');
}