#include "linked_list.h"


/* создать узел с данными */
Node* node_new(int data)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

/* получить адрес n-го узла */
Node* list_get_nth(Node* head, int n)
{
	int counter = 0;

	while (counter < n && head)
	{
		head = head->next;
		counter++;
	}

	return head;
}

/* получить адрес последнего узла */
Node* list_get_last(Node* head)
{
	if (head == NULL)
		return NULL;

	while (head->next)
		head = head->next;

	return head;
}

/* добавить узел в начало списка*/
void list_push(Node **head, Node *node)
{
	node->next = *head;
	*head = node;
}

/* добавить узел в конец списка */
void list_push_back(Node **head, Node *node)
{
	if ((*head) == NULL)
	{
		list_push(head, node);

		return;
	}

	Node *last = list_get_last(*head);

	node->next = NULL;
	last->next = node;
}

/* удалить узел из начала списка */
int list_pop(Node **head)
{
	Node *prev = NULL;
	int pop_val = 0;

	if (*head == NULL)
		exit(-1);

	prev = (*head);
	pop_val = prev->data;
	(*head) = (*head)->next;

	free(prev);

	return pop_val;
}

/* удалить узел из конца списка */
int list_pop_back(Node **head)
{
	int pop_val = 0;

	Node *p_fwd = NULL;  //текущий узел
	Node *p_bwd = NULL;  //предыдущий узел

	if (!head)
		exit(-1);

	if (!(*head))
		exit(-1);

	p_fwd = *head;
	while (p_fwd->next) {
		p_bwd = p_fwd;
		p_fwd = p_fwd->next;
	}

	if (p_bwd == NULL)
	{
		pop_val = (*head)->data;
		free(*head);
		*head = NULL;
	}
	else
	{
		pop_val = (p_fwd)->data;
		free(p_fwd);
		p_bwd = NULL;
	}

	return pop_val;
}

/* получить длину списка */
int list_length(Node *head)
{
	if (head == NULL)
		return 0;

	int len = 1;
	while (head->next)
	{
		head = head->next;
		++len;
	}

	return len;
}

/* очистить список */
void list_free(Node **head)
{
	int len = list_length(*head);

	while (len--)
		list_pop(head);
}
