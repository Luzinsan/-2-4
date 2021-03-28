#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

void getInt(int *choice, int a, int b) 
{
	for (bool flag = scanf("%d", choice);
		flag == 0 || *choice < a || *choice > b;)
	{
		printf("\n\tОшибка! Попробуйте ещё раз.\n\t\t\t");
		if (flag == 0) scanf("%*s");
		flag = scanf("%d", choice);
	}
	getchar();
}
