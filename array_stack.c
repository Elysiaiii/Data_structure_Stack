#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"

ArrayStack* createArrayStack()
{
	ArrayStack* stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	stack->top = -1;
}
void releaseArrayStack(ArrayStack* stack)
{
	stack->top = -1;
}

int pushArrayStack(ArrayStack* stack, Element e)
{
	if (stack->top == MaxStackSize - 1) return NULL;
	stack->data[++stack->top] = e;
	return 0;
}
// Element getArrayStack(ArrayStack *stack);				// ֻ�ǻ�ȡջ����Ԫ�أ�ջ���仯
// int popArrayStack(ArrayStack *stack);					// ֻ�ı�ջ��ջ��Ԫ�ز�����
int popArrayStack(ArrayStack* stack, Element* e)			// ջ����Ԫ�ؿ������ϲ�ռ�
{
	if (stack->top == -1) return NULL;
	*e = stack->data[stack->top--];
	return 0;
}