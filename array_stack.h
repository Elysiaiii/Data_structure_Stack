#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
typedef int Element;
#define MaxStackSize 	5
// ˳��ջ��ջͷ��һ��˳��ջ���ǹ̶���С�ģ�����������
typedef struct {
	Element data[MaxStackSize];				// ջ�ռ�
	int top;								// ջ���������±�
}ArrayStack;

ArrayStack* createArrayStack();
void releaseArrayStack(ArrayStack* stack);

int pushArrayStack(ArrayStack* stack, Element e);
// Element getArrayStack(ArrayStack *stack);				// ֻ�ǻ�ȡջ����Ԫ�أ�ջ���仯
// int popArrayStack(ArrayStack *stack);					// ֻ�ı�ջ��ջ��Ԫ�ز�����
int popArrayStack(ArrayStack* stack, Element* e);			// ջ����Ԫ�ؿ������ϲ�ռ�
#endif

