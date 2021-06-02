/// ��� ����


// 6���� ť �ҽ��� ���⿡...
#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for (b = 0; b < BUCKETS; b++) init(&queues[b]);	// ť���� �ʱ�ȭ

    for (d = 0; d < DIGITS; d++) {
        for (i = 0; i < n; i++)				// �����͵��� �ڸ����� ���� ť�� �Է�
            enqueue(&queues[(list[i] / factor) % 10], list[i]);

        for (b = i = 0; b < BUCKETS; b++)			// ���Ͽ��� ������ list�� ��ģ��.
            while (!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor *= 10;				// �� ���� �ڸ����� ����.
    }
}

#define  SIZE 10

int main(void)
{
    int list[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)      	// ���� ���� �� ��� 
        list[i] = rand() % 100;

    radix_sort(list, SIZE); // ������� ȣ�� 
    for (int i = 0; i < SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
    retu
