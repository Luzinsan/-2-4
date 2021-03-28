/*
Определить структурный тип данных для хранения информации о городах и странах,
в которых они находятся. Создать массив экземпляров этого типа.
Написать функцию, которая печатает названия городов, находящихся в указанной стране.
*/

#include "stdbool.h"
void getInt(int*, int, int);

typedef struct 
{
	char m_name[20];
} City;


typedef struct 
{
	char c_name[20];
	City с_city[9];
} Country;


void createCities(Country *countriesCIS)
{
	char s_cities[9][9][20] = {
								{ "Баку", "Гянджа","Сумгайыт","Ленкорань","Мингечевир","Молдавия","Ширван","Нахичевань","Шамкир" },
								{ "Ереван", "Гюмри","Вагаршапат","Капан","Ванадзор","Раздан","Алаверди","Степанаван","Дилижан" },
								{ "Минск", "Брест","Гродно","Гомель","Витебск","Могилёв","Бобруйск","Барановичи","Новополоцк" },
								{ "Алматы", "Нур-Султан","Шымкент","Актобе","Караганда","Тараз","Павлодар","Усть-Каменогорск","Семей" },
								{ "Бишкек", "Ош","Джалал-Абад","Каракол","Кызыл-кия","Узген","Балыкчы","Кара-Балта","Нарын" },
								{ "Бельцы", "Бендеры","Бессарабка","Бируинца","Бричаны","Быковец","Вадул-луй-Водэ","Ватра","Вулканешты" },
								{ "Москва", "Санкт-Петербург","Новосибирск","Екатеринбург","Казань","Нижний Новгород","Челябинск","Самара","Томск" },
								{ "Бохтар", "Бустон","Вахдат","Гиссар","Гулистон","Душанбе","Истаравшан","Истиклол","Исфара" },
								{ "Ташкент", "Наманган","Самарканд","Андижан","Нукус","Бухара","Карши","Фергана","Коканд" }
							   };
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			strcpy(((countriesCIS+i)->с_city+j)->m_name, s_cities[i][j]);
}

void printTable(Country *countriesCIS)
{
	printf("\n\t____________________________________"
		   "\n\t|     Страна     |      Город      |"
		   "\n\t|**********************************|");
	for (int i = 0; i < 9; i++) 
	{
		printf("\n\t|%16s|%-17s|",(countriesCIS + i)->c_name, ((countriesCIS + i)->с_city)->m_name);
		for (int j = 1; j < 9; j++)
			printf("\n\t|\t\t |%-17s|",((countriesCIS + i)->с_city + j)->m_name);
		printf("\n\t|__________________________________|");
	}
}

void printCities(Country *country) 
{

	printf("\n\t____________________________________"
		   "\n\t|%16s|%-17s|", country->c_name, (country->с_city)->m_name);
	for (int j = 1; j < 9; j++)
		printf("\n\t|\t\t |%-17s|", (country->с_city + j)->m_name);
	printf("\n\t|__________________________________|");

}

void countries()
{
	Country countriesCIS[9];
	char s_country[9][15] = { "Азербайджан", "Армения","Белоруссия","Казахстан","Киргизия","Молдавия","Россия","Таджикистан","Узбекистан"};

	for (int i = 0; i < 9; i++) 
		strcpy((countriesCIS+i)->c_name, s_country[i]);
	
	createCities(&countriesCIS);
	
	int choice = 0;
	printf("\n\tВ базе хранятся страны СНГ. Хотите ввести страну вручную - (1), "
		   "\n\tили посмотреть весь список стран и соответствующих городов - (2)?"
	       "\n\tВаш выбор : ");
	getInt(&choice, 1, 2);

	if(choice == 2) printTable(&countriesCIS);
	else {
		while (1) 
		{
			char country[15];
			bool flag = true;
			printf("\n\tВведите название страны (с большой буквы на кириллице): \n\t");
			gets(country);
			for (int i = 0; i < 9; i++)
				if (!strcmp(s_country[i], country)) { printCities(countriesCIS + i); flag = false; break; }
			if (flag) { printf("\n\tДанной страны нет в базе данных! Попробуйте другую страну.\n"); continue; }
			else break;
		}
	}
}
