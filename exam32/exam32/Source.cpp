#include <iostream>
#include <Windows.h>

using namespace std;

struct Node {
	int element;
	struct Node* next;
};

struct LinkedList {
	struct Node* bottom;
	struct Node* top;
};

void init(LinkedList* list);
void push(LinkedList* list, int element);
Node* pop(LinkedList* list);
void show(LinkedList* list);

int main()
{
	LinkedList* list = new LinkedList;
	
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;

	QueryPerformanceFrequency(&Frequency);

	// initialize linked list
	init(list);

	// start time
	QueryPerformanceCounter(&BeginTime);

	// push the elements
	push(list, 10);
	push(list, 20);
	push(list, 30);
	push(list, 40);
	push(list, 50);

	// elapsed time
	QueryPerformanceCounter(&Endtime);

	// print the elements in stack
	show(list);

	cout << "Performance time: " << (Endtime.QuadPart - BeginTime.QuadPart) / Frequency.QuadPart << endl;

	return 0;
}

void init(LinkedList* list)
{
	list->bottom = NULL;
	list->top = NULL;
}

void push(LinkedList* list, int element)
{
	Node* add = new Node;

	add->element = element;

	if (list->bottom == NULL)
		list->bottom = add;
	else
		list->top->next = add;

	list->top = add;
}

Node* pop(LinkedList* list)
{
	Node* temp = list->top;

	if (list->bottom == list->top) {
		list->bottom = NULL;	
		list->top = NULL;
	}
	else {
		Node* current = list->bottom;
		while (current->next != list->top)
			current = current->next;
		list->top = current;
		current->next = NULL;
	}

	return temp;
}

void show(LinkedList* list)
{
	Node* current = list->bottom;

	cout << "Elements in stack 1: ";
	cout << current->element << " ";
	while (current->next != list->top) {
		current = current->next;
		cout << current->element << " ";
	}
	cout << list->top->element << endl;
}


