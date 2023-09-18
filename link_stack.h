#ifndef LINK_STACK_H
#define LINK_STACK_H
/* ��ʽջ */
typedef int Element;
// ����ڵ�
typedef struct _stack_node {
	Element data;
	struct _stack_node* next;
}stack_node;

// ������ʽջͷ
typedef struct {
	stack_node* top;			// ��ʽջ��ֻ��Ҫ����ջ��ָ��
	int count;					// ͳ��ջѹ���˶��ٸ�Ԫ��
}LinkStack;

LinkStack* createLinkStack();
void releaseLinkStack(LinkStack* stack);

int pushLinkStack(LinkStack* stack, Element e);
int popLinkStack(LinkStack* stack, Element* e);

#endif
