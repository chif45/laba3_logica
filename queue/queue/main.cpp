#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale>

struct node {
	char inf[256];
	struct node* next;
};

struct node* head = NULL;
struct node* last = NULL;

struct node* get_struct()
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
	strcpy(p->inf, s);
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* добавление в список элемента */
void spstore()
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL) {
		head = p;
		last = head;
	}
	else {
		struct node* curr = head;
		head = p;
		p->next = curr;

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
		printf("Имя: %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}


/* Удаление элемента по содержимому. */
void del()
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}
	else
	{
		struct node* curr = head;
		while (curr->next->next != NULL) {
			curr = curr->next;
		}
		curr->next = NULL;
		last = curr;
		
	}

}


int main() {
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < 7; i++) {
		spstore();
	}
	printf("Перед удалением\n");
	review();
	del();
	printf("После удаления\n");
	review();
	return 0;
}