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
// Element getArrayStack(ArrayStack *stack);				// 只是获取栈顶的元素，栈不变化
// int popArrayStack(ArrayStack *stack);					// 只改变栈，栈顶元素不返回
int popArrayStack(ArrayStack* stack, Element* e)			// 栈顶的元素拷贝给上层空间
{
	if (stack->top == -1) return NULL;
	*e = stack->data[stack->top--];
	return 0;
}