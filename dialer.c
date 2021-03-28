/*
Определить структурный тип данных «Телефонная книга» :
(фамилия, номер телефона).
А) Написать функцию, которая по заданной фамилии возвращает номер телефона.
Если фамилии нет, возвращает NULL.
Б) Написать функцию, которая по заданному номеру телефона возвращает фамилию владельца.
Если номера нет, возвращает NULL.
*/
#include "stdbool.h"
void getInt(int*, int, int);

typedef struct
{
	char m_name[20];
	char m_phoneNumber[20];
} PhoneBook;


void printDialer(const PhoneBook *person, const int count) 
{
	printf("\n\t______________________________________"
		   "\n\t|     Фамилия     |  Номер телефона  |"
		   "\n\t|************************************|");
	for (int i = 0; i < count; i++)
		printf("\n\t|%17s|%18s|" 
			   "\n\t|____________________________________|", 
			   (person + i)->m_name, (person + i)->m_phoneNumber);
	
}

void dialer() 
{
	char s_name[10][20] = { "1чел" , "2чел", "3чел","4чел","5чел","6чел","7чел","8чел","9чел","10чел" };
	char s_numbers[10][20] = {"1","2","3","4","5","6","7","8","9","10"};
	int count = 10;
	PhoneBook List[50];
	for (int i = 0; i < count; i++)
	{
		strcpy((List + i)->m_name, s_name[i]);
		strcpy((List + i)->m_phoneNumber, s_numbers[i]);
	}
	
	printf("\n\tВ базе хранятся номера телефонов и фамилии, кому они принадлежат."
		   "\n\tХотите вывести номер телефона по заданной фамилии - (1),"
		   "\n\tвывести фамилию по заданному номеру телефона - (2)"
		   "\n\tпросмотреть весь список - (3)"
	       "\n\tввести новую запись в телефонную книгу - (4)");
	
	int choice = 0;
	while (1)
	{
		printf("\n\n\tВаш выбор №");

		getInt(&choice, 1, 4);

		while (1) 
		{
			bool flag;
			switch (choice)
			{
			case 1://вывести номер телефона по заданной фамилии
				printf("\n\tВведите фамилию: ");
				char name[20];
				gets(name);
				flag = true;

				for (int i = 0; i < count; i++)
					if (!strcmp((List + i)->m_name, name)) 
					{ printf("\n\tНомер телефона: %s", (List+i)->m_phoneNumber); flag = false; break; }
				
				if (flag) { printf("\n\tДанной фамилии нет в базе данных. Попробуйте ещё раз.\n"); continue; }
				else break;

			case 2://вывести фамилию по заданному номеру телефона
				printf("\n\tВведите номер телефона: ");
				char number[20];
				gets(number);
				flag = true;
				
				for (int i = 0; i < count; i++)
					if (!strcmp((List+i)->m_phoneNumber, number)) 
					{ printf("\n\tФамилия: %s", (List+i)->m_name); flag = false; break; }
				
				if (flag) { printf("\n\tДанного номера телефона нет в базе данных. Попробуйте ещё раз.\n"); continue; }
				else break;

			case 3://просмотреть весь список
				printDialer(List, count);
				break;

			case 4://ввести новую запись в телефонную книгу
				
				printf("\n\tФамилия: ");
				gets((List+count)->m_name);
				printf("\n\tНомер телефона: ");
				gets((List + count)->m_phoneNumber);
				
				flag = false;
				for (int i = 0; i < count; i++)
					if (!strcmp((List + count)->m_name, (List + i)->m_name) 
						&& !strcmp((List + count)->m_phoneNumber, (List + i)->m_phoneNumber))
					{ printf("\n\tТакая запись уже есть! Попробуйте ещё раз."); count--; flag = true; }
				if (flag) continue;
				else printf("\n\tЗапись успешно введена.");
				count++;
				break;

			default:
				printf("\n\tОшибка! Что-то пошло не так...");
			}
			break;
		}
		printf("\n\tЖелаете продолжить? (Да/Нет) ");
		char answer[256];
		while (gets(answer) && strcmp(answer, "Да") && strcmp(answer, "Нет"))
			printf("\n\tОшибка! Введите корректный ответ.\n\t\t\t");

		if (!strcmp(answer, "Да")) continue; else break;
	}
}
