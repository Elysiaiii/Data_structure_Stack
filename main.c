/* 栈还是依赖于线性表的结构，只是比普通的线性表的插入和删除（操作）做了一个约束
 * 线性表（顺序表、链式表），
 * 		任意位置的插入，任意位置的删除，任意的访问
 * 增加访问约束
 * 1. 插入、删除、访问（读写）只能在一端进行			栈
 * 2. 插入、删除、访问（读写）只能在一端读，一端写		队列
 *
 * 栈的特性，有什么意义？  后悔   倒着走
 * 1. 历史记录     ctrl+z   undo撤销
 * 2. 逆序
 * 3. 函数的调用关系
 * 栈的分类：
 * 1. 顺序栈有分类：
 * 		栈指针 		指向有效空间		指向无效空间
 * 				 	 	满				空
 * 		栈的生长空间		递增				递减
 * 	4种：C语言的编译器内部会对所有的函数进行栈空间的使用，默认栈是： 满递减栈
 * 	OS为了保证各个子函数能够顺利运行，对每个子函数的栈空间做了最大值限制，如果超过了这个限制，OS就会杀死这个进程
 * 		栈溢出的错误
 *
 * 顺序栈的实现：
 * 	函数里，定义一个数组空间，一个索引号，实现一个临时栈
 * */
#include <stdio.h>
#include "link_stack.h"

 // 满递增栈
void easy_stack() {
#define MAX_STACK_SIZE 5
	int array[MAX_STACK_SIZE];
	int pos = -1;

	for (int i = 0; i < 6; ++i) {
		// 入栈，一旦栈满了，就不能再入
		array[++pos] = i + 100;
		if (pos >= MAX_STACK_SIZE - 1) {
			break;
		}
	}

	// 出栈，打印，一直出栈，直到栈为空
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