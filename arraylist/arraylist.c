#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int element;
typedef struct {
	element array[MAX];
	int size;
}ArrayListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}

void init(ArrayListType* L)
{
	L->size = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("위치오류");
	return L->array[pos];
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX)
	{
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
	
}
void insert(ArrayListType* L, int pos, element item)
{
	int move = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];
			move++;
		}
		
		L->array[pos] = item;
		L->size++;
		printf("Move : %d", move);
	}
}

element delete(ArrayListType* L, int pos)
{
	element item;
	int move = 0;
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
	{
		L->array[i] = L->array[i + 1];
		move++;
	}
	
	L->size--;
	
	printf("Move : %d", pos - (L->size - 1));
	return item;
}

int main(void)
{
	ArrayListType L;
	int element;
	init(&L);
	int s = 0;
	int pos = 0;
	while (1)
	{
		printf("\n= = = = Menu = = = =\n");
		printf("1. Insert \n2. Delete \n3. Print \n4. Exit\n");
		printf("Slect Menu = ");
		scanf_s("%d", &s);
		if (s == 1 && !is_full(&L))
		{
			printf("\nEnter the position: ");
			scanf_s("%d %d", &pos ,&element);
			insert(&L, pos, element);
			printf("\n");
		}
		else if (s == 2 && !is_empty(&L))	
		{
			printf("\nDelete the position: ");
			scanf_s("%d", &pos);
			delete(&L, pos);
			
			
		}
		else if (s == 1 && is_full(&L))
		{
			printf("List is full");
		}
		else if (s == 2 && is_empty(&L))
		{
			printf("List is empty");
		}
		else if (s == 3)
		{
			print_list(&L);
		}

		else if (s == 4) {
			printf("Exit the program");
			break;
		}
		else {
			printf("잘못된 입력입니다. 다시 입력 해주세요\n");

		}
	}
}