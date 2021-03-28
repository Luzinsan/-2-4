/*
Определить структурный тип данных для хранения информации о городах и странах, 
в которых они находятся. Создать массив экземпляров этого типа.
Написать функцию, которая печатает названия городов, находящихся в указанной стране.

Определить структурный тип данных для хранения информации о товарах :
наименование, цена в рублях и копейках. 
Написать функцию, возвращающую название более дорогого из двух указанных товаров.

Определить структурный тип данных «Телефонная книга» : 
(фамилия, номер телефона).
	А) Написать функцию, которая по заданной фамилии возвращает номер телефона.
	Если фамилии нет, возвращает NULL.
	Б) Написать функцию, которая по заданному номеру телефона возвращает фамилию владельца.
	Если номера нет, возвращает NULL.
*/
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <stdbool.h>

void countries();
void priceСomparison();
void dialer();
void getInt(int*, int, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	{
		printf("\n\t\t\tПрограмма №1 (База стран и их городов)"
			"\n\tВ базе хранятся страны СНГ и первые 9 самых больших городов этих стран."
			"\n\tНеобходимо ввести вручную название страны на кирилице. Программа выведет список городов этой страны."
			"\n\tЛибо выведет все страны и их города.");
		printf("\n\n\t\t\tПрограмма №2 (Склад, сравнение цен)"
			"\n\tНеобходимо ввести два товара: их названия, цена в рублях, цена в копейках."
			"\n\tНа выход Вы получите наименование более дорогого из двух указанных товаров.");
		printf("\n\n\t\t\tПрограмма №3 (Телефонная книга)"
			"\n\tНа выбор пользователя программа:"
			"\n\tВыводит фамилию или номер телефона в зависимости от введённых данных."
			"\n\tВыводит список фамилийи и соответствующих им номеров телефона, которые внесены в базу."
			"\n\tЕсли в базе нет нужных данных, есть возможность внести их в базу. (максимальное количество номеров - 50)");
	}

	int choice = 0;
	while (1) 
	{
		printf("\n\n\tВсего программ - (3)."
			     "\n\tЗапустить программу №");
		
		getInt(&choice, 1, 3);
		
		switch (choice) 
		{
		case 1:
			countries();
			break;
		case 2:
			priceСomparison();
			break;
		case 3:
			dialer();
			break;
		default:
			printf("\n\tОшибка! Что-то пошло не так...");
		}
		printf("\n\n\tЖелаете выбрать другую программу? (Да/Нет) ");
		char answer[256];
		while (gets(answer) && strcmp(answer, "Да") && strcmp(answer, "Нет")) 
			printf("\n\tОшибка! Введите корректный ответ.\n\t\t\t");
		
		if (!strcmp(answer, "Да")) continue; else break;
	}
	
	getch();
	return 0;
}