#include"list.h"
#include<stdio.h>
#include<stdlib.h>

/*
*�����ڵ�
*/
node_t * create_node(int value)
{
	node_t *node = (node_t*)malloc(sizeof(node_t));
	if (node != NULL) {
		node->next = NULL;
		node->value = value;
	}
	return node;
}

void insert_sort(node_t * head)
{
	node_t *p = head->next, *q = NULL, *r = NULL;  //pָ���һ�����ݽڵ�
	if (p != NULL)                                     //��������һ���������ϵ����ݽڵ�
	{
		r = p->next;                      //r ���� *p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
		p->next = NULL;            //����ֻ����һ�����ݽڵ�������
		p = r;
		while (p != NULL)
		{
			r = p->next;            //r ����*p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
			q = head;
			while (q->next != NULL && q->next->value< p->value)
				q = q->next;     //��������в��Ҳ���*p��ֱ��ǰ���ڵ�*q��λ��
			p->next = q->next;                   //��*p���뵽*q֮��
			q->next = p;
			p = r;                               //ɨ��ԭ���������µĽڵ�
		}
	}
}


void delete_list(node_t *head)
{
	node_t *t_node, *p_node;
	if (head != NULL) {
		p_node = head;
		t_node = head->next;
		while (t_node != NULL)
		{
			p_node = t_node;
			t_node = t_node->next;
			free(p_node);
		}
		free(head);
	}
}

void reverse(node_t * head)
{
	node_t *t_node;
	if (head != NULL)
	{
		t_node = head->next;
	}
}

void insert_node_h(node_t *head, node_t *node)
{
	node_t *t_node;
	if (head != NULL)
	{
		t_node = head->next;
		node->next = t_node;
		head->next = node;
		head->value++;
	}
}

void insert_node_t(node_t *head, node_t *node)
{
	node_t *t_node, *p_node;
	if (head != NULL)
	{
		p_node = head;
		t_node = head->next;
		while (t_node != NULL)
		{
			p_node = t_node;
			t_node = t_node->next;
			head->value++;
		}
		p_node->next = node;
	}
}

void print_list(node_t *head)
{
	node_t *t_node;
	if (head != NULL) {
		t_node = head->next;
		while (t_node != NULL)
		{
			printf("%d\n", t_node->value);
			t_node = t_node->next;
		}
	}
}


void test_list()
{
	node_t *head, *node;
	int value, i;
	head = create_node(0);
	for (i = 0; i < 20000; i++)
	{
		value = rand();
		node = create_node(value);
		insert_node_h(head, node);
	}
	insert_sort(head);
	print_list(head);
}
