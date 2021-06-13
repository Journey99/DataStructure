/* 스택(stack) : 쌓아놓은 더미
       -후입선출(LIFO) : 가장 최근에 들어온 데이터가 먼저 나감
       - 스택상단 top 과 스택하단 bottom 으로 이루어짐

       <추상데이터타입>
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

//전역변수 사용

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
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }

    else
        stack[++top] = item;
}

element pop()
{
    if (is_empty())
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }

    else
        return stack[top--];
}

element peek()
{
    if (is_empty())
    {
        fprintf(stderr, "스택 공백 에러\n");
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

//구조체 배열 사용하기

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
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        s->data[++(s->top)] = item;

}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
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

// 동적 스택
// 다 똑같고 main 함수에서 s = (StackType *)malloc(sizeof(StackType)); 동적할당 해준다.

// 괄호 검사 프로그램
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

/* 스택 초기화 함수 */
void init(StackType* s)
{
    s->top = -1;
}

/* 공백 상태 검출 함수 */
int is_empty(StackType* s)
{
    return (s->top == -1);
}

/* 포화 상태 검출 함수 */
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

/* 삽입 함수 */
void push(StackType* s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }

    else
        s->stack[++(s->top)] = item;
}

/* 삭제 함수 */
element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }

    else
        return s->stack[(s->top)--];
}

/* 피크 함수 */
element peek(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }

    else
        return s->stack[s->top];
}

/* 위치를 스택에 삽입 */
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
            printf("실패\n");
            return;
        }

        else
            here = pop(&s);
    }

    printf("성공\n");

    return 0;
}
