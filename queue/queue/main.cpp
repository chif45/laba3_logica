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
	if ((p == NULL)) // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

/* ���������� � ������ �������� */
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

/* �������� ����������� ������. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("���: %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}


/* �������� �������� �� �����������. */
void del()
{
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
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
	printf("����� ���������\n");
	review();
	del();
	printf("����� ��������\n");
	review();
	return 0;
}