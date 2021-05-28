// ���� Ž�� Ʈ��

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

// ��ȯ���� Ž�� �Լ�
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if(key == node->key) return node;
	
}

/*
-�ݺ����� ���
TreeNode *serach(TreeNode *node, int key){
	while(node != NULL){
		if(key == node->key) return node;
		else if(key < node->key)
			node = node ->left;
		else node = node->rigth;
	}
	return NULL - �������� ���
}
*/

// ���Կ���

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// ��������
// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);

	else {
		//ù��°�� �ι�° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		//����° ���
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);

	}
	return root;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;

	return current;
}


int main(void) {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰���!\n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸���!\n");
	return 0;
}