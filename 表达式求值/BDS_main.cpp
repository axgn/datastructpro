#include"BDS.h"

int main()
{
	int i;
	printf("\n\n\n\nOnly within Positive integer evaluation,input a expression end with symbol #:(7+(3+8)*5#)\n");
	i = EvaluateExpression(); 
	if (!i)
	{
		printf("\nERROR!");
	}
	else 
	{
		printf("\nThis expression's result is:   ");
		printf("%d\n\n\n\n", i);
		printf("kkkkk");
	}

}