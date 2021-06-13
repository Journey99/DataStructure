/* ����(stack) : �׾Ƴ��� ����
       -���Լ���(LIFO) : ���� �ֱٿ� ���� �����Ͱ� ���� ����
       - ���û�� top �� �����ϴ� bottom ���� �̷����

       <�߻�����Ÿ��>
       - is_full(s)
       - is_empty(s)
       - push(s,item)
       - pop(s)
       - peek(s)
*/

/*
is_empty:
    if top == -1
        then return True;
    else return FALSE;

is_full:
    if top == (MAX_STACK_SIZE - 1)
        then return True

push:
    if is_full()
        then error "overflow"
    else top <- top+1;
         stack[top] <- x

pop:
    if is_empty()
        then error
    else e <- stack[top]
        top <- top - 1
        return e
*/

//�������� ���

/* #include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}

void push(element item)
{
    if (is_full())
    {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }

    else
        stack[++top] = item;
}

element pop()
{
    if (is_empty())
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }

    else
        return stack[top--];
}

element peek()
{
    if (is_empty())
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }

    else
        return stack[top];
}

int main()
{
    push(1);
    push(2);
    push(3);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", is_empty());

    return 0;
}
*/

//����ü �迭 ����ϱ�

/*#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else
        s->data[++(s->top)] = item;

}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else
        return s->data[(s->top)--];

}

int main(void) {
    StackType* s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

} */

// ���� ����
// �� �Ȱ��� main �Լ����� s = (StackType *)malloc(sizeof(StackType)); �����Ҵ� ���ش�.

// ��ȣ �˻� ���α׷�
/* int check_matching(const char* in)
{
    StackType* s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch(ch)
        {
        case '(':
        case '{':
        case '[':
            push(&s, ch);
            break;
        case ')': case'}': case']':
            if (is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') || (open_ch == '{' && ch != '}') || (open_ch == '[' && ch != ']'))
                    return 0;

            }
            break;
        }

    }
    if (!is_empty(&s)) return 0;
    return 1;
}
*/

#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0
#define MAZE_SIZE 6

typedef struct
{
    short r;
    short c;
} element;

element here = { 1, 0 }, entry = { 1, 0 };

char maze[MAX_STACK_SIZE][MAX_STACK_SIZE] =
{
    { '1', '1', '1', '1', '1', '1' },
    { 'e', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' },
};

typedef struct
{
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

/* ���� �ʱ�ȭ �Լ� */
void init(StackType* s)
{
    s->top = -1;
}

/* ���� ���� ���� �Լ� */
int is_empty(StackType* s)
{
    return (s->top == -1);
}

/* ��ȭ ���� ���� �Լ� */
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

/* ���� �Լ� */
void push(StackType* s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }

    else
        s->stack[++(s->top)] = item;
}

/* ���� �Լ� */
element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }

    else
        return s->stack[(s->top)--];
}

/* ��ũ �Լ� */
element peek(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }

    else
        return s->stack[s->top];
}

/* ��ġ�� ���ÿ� ���� */
void push_loc(StackType* s, int r, int c)
{
    if (r < 0 || c < 0)
        return;

    if (maze[r][c] != '1' && maze[r][c] != '.')
    {
        element tmp;

        tmp.r = r;
        tmp.c = c;

        push(s, tmp);
    }
}

int main()
{
    int r, c;
    StackType s;

    init(&s);

    here = entry;

    while (maze[here.r][here.c] != 'x')
    {
        r = here.r;
        c = here.c;

        maze[r][c] = '.';

        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);

        if (is_empty(&s))
        {
            printf("����\n");
            return;
        }

        else
            here = pop(&s);
    }

    printf("����\n");

    return 0;
}
