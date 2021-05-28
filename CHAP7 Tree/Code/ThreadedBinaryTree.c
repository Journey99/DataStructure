// ������ ���� Ʈ��

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;


// ���� �ļ��� ã�� �Լ�
TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;
	while (q->left != NULL) q = q->left;
	return q;
}

// ������ ���� ���� ��ȸ �Լ�
void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;
	while (q->left) q = q->left;
	do {
		printf("%c", q->data);
		q = find_successor(q);

	} while (q);
}

