#include"BDS.h"
#include "second_solu.h"
#include <iostream>
int main()
{
	int choose;
	printf("choose your way(1or2):\n");
	std::cin >> choose;
	if (choose == 1)
	{
		int ignore;
		ignore =  getchar();
		int i = 0;
		printf("Only within Positive integer evaluation,input a expression end with symbol #:(7+(3+8)*5#)\n");
		i = EvaluateExpression();
		if (!i)
		{
			printf("\nERROR!");
		}
		else
		{
			printf("\nThis expression's result is:   ");
			printf("%d\n", i);
		}
	}
	else if(choose == 2)
	{
		int ignore;
		ignore = getchar();
		printf("Only within Positive integer evaluation:(7+(3+8)*5)\n");
		std::string s;
		std::getline(std::cin, s);
		if (check(s))
		{
			printf("This expression's result is:%d", evaluate(s));
		}
		else
		{
			printf("error\n");
		}
	}
	else
	{
		printf("error\n");
	}
	return 0;
}