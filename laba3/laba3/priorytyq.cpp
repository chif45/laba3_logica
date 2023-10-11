#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale>

struct node {
    char inf[256];
	int priority;
    struct node* next;
};

struct node* head = NULL;

struct node* get_struct(int priority)
{
	struct node* p = NULL;
	char s[256];
	p = (node*)malloc(sizeof(struct node));
	if ((p == NULL)) // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	p->priority = priority;
	strcpy(p->inf, s);
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента */
void spstore(int priority)
{
	struct node* p = NULL;
	p = get_struct(priority);
	if (head == NULL || priority > head->priority) {
		p->next = head;
		head = p;
	}
	else {
		struct node* curr = head;
		while (curr->next != NULL && priority < curr->next->priority) {
			curr = curr->next;
		}
		p->next = curr->next;
		curr->next = p;
	}
	return;
}

/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("Приоритет: %d Имя: %s, \n",struc->priority, struc->inf);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}

/* Удаление элемента по содержимому. */
void del(char* name)
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev;// указатель на предшествующий удаляемому элемент
	int flag = 0;      // индикатор отсутствия удаляемого элемента в списке

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // если удаляемый элемент - первый
	{
		flag = 1;
		head = struc->next; // установливаем голову на следующий элемент
		free(struc);  // удаляем первый элемент
		struc = head; // устанавливаем указатель для продолжения поиска
		return;
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // проход по списку и поиск удаляемого элемента
	{
		if (strcmp(name, struc->inf) == 0) // если нашли, то
		{
			flag = 1;         // выставляем индикатор
			if (struc->next)  // если найденный элемент не последний в списке
			{
				prev->next = struc->next; // меняем указатели
				free(struc);		    // удаляем  элемент
				struc = prev->next; // устанавливаем указатель для продолжения поиска
			}
			else			// если найденный элемент последний в списке
			{
				prev->next = NULL; // обнуляем указатель предшествующего элемента
				free(struc);	// удаляем  элемент
				return;
			}
		}
		else // если не нашли, то
		{
			prev = struc; // устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}
	}

	if (flag == 0)				// если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент не найден\n");
		return;
	}


}


int main() {
	setlocale(LC_ALL, "Rus");
	int pr;
	for (int i = 0; i < 5; i++) {
		printf("Введите приоритет элемента:\n");
		scanf("%d", &pr);
		spstore(pr);
	}
	review();
	char s[256] = {1};
	printf("Введите удаляемый элемент: \n");
	scanf("%s", s);
	del(s);
	review();
	return 0;
}