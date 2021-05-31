// 위상정렬을 수행한다.
int topo_sort(GraphType* g)
{
	int i;
	StackType s;
	GraphNode* node;

	// 모든 정점의 진입 차수를 계산
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)			// 초기화
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];//정점 i에서 나오는 간선들
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}
	// 진입 차수가 0인 정점을 스택에 삽입
	init(&s);
	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) push(&s, i);
	}
	// 위상 순서를 생성 
	while (!is_empty(&s)) {
		int w;
		w = pop(&s);
		printf("정점 %d ->", w);		//정점 출력
		node = g->adj_list[w];	//각 정점의 진입 차수를 변경
		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--;			//진입 차수를 감소
			if (in_degree[u] == 0) push(&s, u);
			node = node->link;   // 다음 정점
		}
	}
	free(in_degree);
	printf("\n");
	return (i == g->n);	// 반환값이 1이면 성공, 0이면 실패
}

int main(void)
{
	GraphType g;

	graph_init(&g);
	insert_vertex(&g, 0);	insert_vertex(&g, 1);
	insert_vertex(&g, 2);	insert_vertex(&g, 3);
	insert_vertex(&g, 4);	insert_vertex(&g, 5);

	//정점 0의 인접 리스트 생성
	insert_edge(&g, 0, 2);	insert_edge(&g, 0, 3);
	//정점 1의 인접 리스트 생성
	insert_edge(&g, 1, 3);	insert_edge(&g, 1, 4);
	//정점 2의 인접 리스트 생성
	insert_edge(&g, 2, 3);	insert_edge(&g, 2, 5);
	//정점 3의 인접 리스트 생성
	insert_edge(&g, 3, 5);	//정점 4의 인접 리스트 생성
	insert_edge(&g, 4, 5);
	//위상 정렬 
	topo_sort(&g);
	// 동적 메모리 반환 코드 생략
	return 0;
}
