/* ջ�������������Ա�Ľṹ��ֻ�Ǳ���ͨ�����Ա�Ĳ����ɾ��������������һ��Լ��
 * ���Ա�˳�����ʽ����
 * 		����λ�õĲ��룬����λ�õ�ɾ��������ķ���
 * ���ӷ���Լ��
 * 1. ���롢ɾ�������ʣ���д��ֻ����һ�˽���			ջ
 * 2. ���롢ɾ�������ʣ���д��ֻ����һ�˶���һ��д		����
 *
 * ջ�����ԣ���ʲô���壿  ���   ������
 * 1. ��ʷ��¼     ctrl+z   undo����
 * 2. ����
 * 3. �����ĵ��ù�ϵ
 * ջ�ķ��ࣺ
 * 1. ˳��ջ�з��ࣺ
 * 		ջָ�� 		ָ����Ч�ռ�		ָ����Ч�ռ�
 * 				 	 	��				��
 * 		ջ�������ռ�		����				�ݼ�
 * 	4�֣�C���Եı������ڲ�������еĺ�������ջ�ռ��ʹ�ã�Ĭ��ջ�ǣ� ���ݼ�ջ
 * 	OSΪ�˱�֤�����Ӻ����ܹ�˳�����У���ÿ���Ӻ�����ջ�ռ��������ֵ���ƣ����������������ƣ�OS�ͻ�ɱ���������
 * 		ջ����Ĵ���
 *
 * ˳��ջ��ʵ�֣�
 * 	���������һ������ռ䣬һ�������ţ�ʵ��һ����ʱջ
 * */
#include <stdio.h>
#include "link_stack.h"

 // ������ջ
void easy_stack() {
#define MAX_STACK_SIZE 5
	int array[MAX_STACK_SIZE];
	int pos = -1;

	for (int i = 0; i < 6; ++i) {
		// ��ջ��һ��ջ���ˣ��Ͳ�������
		array[++pos] = i + 100;
		if (pos >= MAX_STACK_SIZE - 1) {
			break;
		}
	}

	// ��ջ����ӡ��һֱ��ջ��ֱ��ջΪ��
	while (pos > -1) {
		printf("%d\t", array[pos--]);
	}
	printf("\n");
}

void test01() {
	LinkStack* stack = createLinkStack();

	for (int i = 0; i < 5; ++i) {
		pushLinkStack(stack, i + 50);
	}
	printf("pop:\n");
	Element val;
	while (popLinkStack(stack, &val) == 0) {
		printf("%d\t", val);
	}
	printf("\n");

	releaseLinkStack(stack);
}

int main() {
	easy_stack();
	return 0;
}