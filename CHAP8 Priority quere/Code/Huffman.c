# ������ �ڵ�

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
	int weigth;
	char ch;
	struct TreeNode* left;
	struct TeeNode* right;

}TreeNode;

typedef struct {
	TreeNode* ptree;
	char ch;
	int key;

}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;

}HeapType;

// �����Լ�
HeapType* create() {
	return (HeapType *)malloc(sizeof(HeapType))
}

// �ʱ�ȭ�Լ�
void init(HeapType* h) {
	h->heap_size = 0;
}

// ���� �Լ�
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ��
	while (i != 1) && (item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2; // �θ� ���
	}

	h->heap[i] = item;

}

// ���� �Լ�
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�

		if ((chlid < h->heap_size) && (h->heap[chile].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = chlid;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// ����Ʈ�� ���� �Լ�
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

// ����Ʈ�� ���� �Լ�
void destory_tree(TreeNode* root) {
	if (root == NULL) return;
	destory_tree(root->left);
	destory_tree(root->right);
	free(root);
}

int is_leaf(TreeNode* root) {
	return !(root->left) && !(root->right);
}

void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top) {
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}

	//�ܸ�����̸� �ڵ带 ���
	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}

// ������ �ڵ� ���� �Լ�
void huffman_tree(int freq[], char ch_list[], int n) {
	int i;
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = creat();
	init(heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}

	for (i = 1; i < n; i++) {
		e1 = delete_max_heap(heap);
		e2 = delete_max_heap(heap);
		// �ΰ��� ��带 ��ģ��.
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weigth = e1.key + e2.key;
		e.ptree = x;
		printf("%d + %d -> %d\n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}
	e = delete_max_heap(heap); //����Ʈ��
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);
}

int main(void) {
	char ch_list[] = { 's', 'i', 'n', 't', 'e' };
	int freq[] = { 4, 6, 8, 12, 15 };
	huffman_tree(freq, ch_list, 5);
	return 0;
}