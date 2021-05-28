// 이진 탐색 트리

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

// 순환적인 탐색 함수
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if(key == node->key) return node;
	
}

/*
-반복적인 방법
TreeNode *serach(TreeNode *node, int key){
	while(node != NULL){
		if(key == node->key) return node;
		else if(key < node->key)
			node = node ->left;
		else node = node->rigth;
	}
	return NULL - 실패했을 경우
}
*/

// 삽입연산

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

// 삭제연산
// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);

	else {
		//첫번째나 두번째 경우
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

		//세번째 경우
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

	printf("이진 탐색 트리 중위 순회 결과\n");
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함!\n");
	else
		printf("이진 탐색 트리에서 30을 발견못함!\n");
	return 0;
}