// 히프 정렬 

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define SIZE 8

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

// 삽입 함수
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교
	while (i != 1) && (item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2; // 부모 노드
	}

	h->heap[i] = item;

}

// 삭제 함수
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다

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

// 우선 순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n) {
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}

	for (i = (n - 1); i >= 0; i--) {
		a[i] delete_max_heap(h);
	}
	free(h);

}

int main(void) {
	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d", list[i].key);
	}
	printf("\n");
	return 0;
}