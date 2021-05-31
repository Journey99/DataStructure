// ���������� �����Ѵ�.
int topo_sort(GraphType* g)
{
	int i;
	StackType s;
	GraphNode* node;

	// ��� ������ ���� ������ ���
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)			// �ʱ�ȭ
		in_degree[i] = 0;
	for (i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i];//���� i���� ������ ������
		while (node != NULL) {
			in_degree[node->vertex]++;
			node = node->link;
		}
	}
	// ���� ������ 0�� ������ ���ÿ� ����
	init(&s);
	for (i = 0; i < g->n; i++) {
		if (in_degree[i] == 0) push(&s, i);
	}
	// ���� ������ ���� 
	while (!is_empty(&s)) {
		int w;
		w = pop(&s);
		printf("���� %d ->", w);		//���� ���
		node = g->adj_list[w];	//�� ������ ���� ������ ����
		while (node != NULL) {
			int u = node->vertex;
			in_degree[u]--;			//���� ������ ����
			if (in_degree[u] == 0) push(&s, u);
			node = node->link;   // ���� ����
		}
	}
	free(in_degree);
	printf("\n");
	return (i == g->n);	// ��ȯ���� 1�̸� ����, 0�̸� ����
}

int main(void)
{
	GraphType g;

	graph_init(&g);
	insert_vertex(&g, 0);	insert_vertex(&g, 1);
	insert_vertex(&g, 2);	insert_vertex(&g, 3);
	insert_vertex(&g, 4);	insert_vertex(&g, 5);

	//���� 0�� ���� ����Ʈ ����
	insert_edge(&g, 0, 2);	insert_edge(&g, 0, 3);
	//���� 1�� ���� ����Ʈ ����
	insert_edge(&g, 1, 3);	insert_edge(&g, 1, 4);
	//���� 2�� ���� ����Ʈ ����
	insert_edge(&g, 2, 3);	insert_edge(&g, 2, 5);
	//���� 3�� ���� ����Ʈ ����
	insert_edge(&g, 3, 5);	//���� 4�� ���� ����Ʈ ����
	insert_edge(&g, 4, 5);
	//���� ���� 
	topo_sort(&g);
	// ���� �޸� ��ȯ �ڵ� ����
	return 0;
}
