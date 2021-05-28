// 스레드 이진 트리

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;


// 중위 후속자 찾는 함수
TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;
	while (q->left != NULL) q = q->left;
	return q;
}

// 스레드 버전 중위 순회 함수
void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;
	while (q->left) q = q->left;
	do {
		printf("%c", q->data);
		q = find_successor(q);

	} while (q);
}

