/*
< Priority queue - 우선순위 큐 >
 : 우선순위를 가진 항목들을 저장하는 큐
   FIFO 순서가 아니라 우선 순위가 높은 데이터가 먼저 나가게 된다

   응용분야 ex) 시뮬레이션 시스템, 네트워크 트래픽 제어, 운영 체제에서의 작업 스케쥴링

- 우선순위 큐
	*최소 우선순위 큐
	*최대 우선순위 큐

- 우선순위 큐 구현방법
	* 배열을 이용한
	* 연결리스트를 이용한
	* 히프를 이용한  -> 이진트리의 한종류

- 히프
   : 노드의 키들이 key(부모노드) >= key(자식노드) 를 만족하는 완전이진트리

   # 히프의 종류
     *최대 히프
	 *최소 히프

   # 히프의 성질
     1) n개의 노드를 가지고 있는 히프의 높이는 O(logn)
	 2) 히프는 배열을 이용하여 구현   -> 각 노드에 번호를 붙일 수 있다
	 3) 부모노드와 자식노드를 찾기가 쉽다

   #히프의 정의
		#define MAX_ELEMENT 200
		typedef struct{
			int key;
		} element;

		typedef struct{
			element heap[MAX_ELEMENT];
			int heap_size;
		} HeapType;

		HeapType heap; // 정적 메모리 할당
		HeapType *heap = create(); // 동적 메모리 할당   
	
	
	
	
*/