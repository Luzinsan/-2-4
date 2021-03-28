/*
Определить структурный тип данных для хранения информации о товарах :
наименование, цена в рублях и копейках. 
Написать функцию, возвращающую название более дорогого из двух указанных товаров.
*/
#include "stdbool.h"
void getInt(int*, int, int);

typedef struct 
{
	char m_name[50];
	int rub;
	int kop;
} Goods;


void priceСomparison()
{
	Goods product[2];

	for (int i = 0; i < 2; i++) 
	{
		printf("\n\tВведите название товара №%d: ", i+1);
		gets((product+i)->m_name);

		printf("\n\tВведите цену этого товара в рублях: ");
		for (bool flag = scanf("%d", &((product + i)->rub)); 
			flag == 0 || (product + i)->rub < 1;)
		{
			printf("\n\tОшибка! Попробуйте ещё раз.\n\t\t\t");
			if (flag==0) scanf("%*s");
			flag = scanf("%d", &((product + i)->rub));
		}

		printf("\n\tВведите цену этого товара в копейках[1,99]: ");
		for (bool flag = scanf("%d", &((product + i)->kop)); 
			flag == 0 || (product + i)->kop < 1 || (product + i)->kop >= 100;)
		{
			printf("\n\tОшибка! Попробуйте ещё раз.\n\t\t\t");
			if (flag == 0) scanf("%*s");
			flag = scanf("%d", &((product + i)->kop));
		}
		getchar();
	}
	
	printf("\n\tНаиболее дорогим товаром из введённых является: "
	  	   "%s", (product->rub * 100 + product->kop > (product + 1)->rub * 100 + (product + 1)->kop)
		   ? product->m_name : (product + 1)->m_name);
}
