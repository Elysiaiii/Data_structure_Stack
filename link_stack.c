#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"

LinkStack* createLinkStack()
{
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	if (stack == NULL)
	{
		printf("link stack malloc failed!\n");
		return NULL;
	}
	stack->count = 0;
	stack->top = NULL;
	return stack;
}
void releaseLinkStack(LinkStack* stack)
{
	if (stack)
	{
		while (stack->top)
		{
			stack_node* tmp = stack->top->next;
			stack->top->next = tmp->next;
			free(tmp);
			--stack->count;
		}
		printf("stack node : %d\n", stack->count);
		free(stack);
	}
}

int pushLinkStack(LinkStack* stack, Element e)
{
	stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));
	if (new_node == NULL)
	{
		printf("node malloc failed!\n");
		return NULL;
	}
	new_node->data = e;

	new_node->next = stack->top->next;
	stack->top = new_node;
	++stack->count;
	return 0;
}
int popLinkStack(LinkStack* stack, Element* e)
{
	if (stack->top == NULL)
	{
		printf("no element!\n");
		return NULL;
	}
	*e = stack->top->data;
	stack_node* tmp = stack->top->next;
	stack->top = tmp->next;		//----------×¢Òâ²»ÊÇstack->top->next£¡------------//
	free(tmp);
	--stack->count;
	return 0;
}