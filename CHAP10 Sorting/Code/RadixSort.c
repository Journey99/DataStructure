/// 기수 정렬


// 6장의 큐 소스를 여기에...
#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];

    for (b = 0; b < BUCKETS; b++) init(&queues[b]);	// 큐들의 초기화

    for (d = 0; d < DIGITS; d++) {
        for (i = 0; i < n; i++)				// 데이터들을 자리수에 따라 큐에 입력
            enqueue(&queues[(list[i] / factor) % 10], list[i]);

        for (b = i = 0; b < BUCKETS; b++)			// 버켓에서 꺼내어 list로 합친다.
            while (!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor *= 10;				// 그 다음 자리수로 간다.
    }
}

#define  SIZE 10

int main(void)
{
    int list[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)      	// 난수 생성 및 출력 
        list[i] = rand() % 100;

    radix_sort(list, SIZE); // 기수정렬 호출 
    for (int i = 0; i < SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
    retu
