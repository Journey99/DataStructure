/*
	자체참조 구조체
	  -필드중에 자기 자신을 가리키는 포인터가 한개이상 존재하는 구조체
	  ex)연결리스트, 트리
	배열
	  -같은 형의 변수를 여러개 만들때
*/

// 1-(1). 다항식의 표현방법1 - 모든 항 다 저장

/*
#include <stdio.h>
#define MAX(a,b)  (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;

		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void main() {
	polynomial a = { 5, {3,6,0,0,0,10} };
	polynomial b = { 4, {7,0,5,0,1} };
	polynomial c;
	c = poly_add1(a, b);

} */

// 1-(2). 다항식 표현방법2 - 0이 아닌 항만을 배열에 저장

/* #include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

struct
{
	float coef;
	int expon;
} terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };
int avail = 6;

char compare(int a, int b)
{
	if (a > b)
		return '>';
	else if (a == b)
		return '=';
	else
		return '<';
}
// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}
// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float tempcoef;
	*Cs = avail;

	while (As <= Ae && Bs <= Be)
	{
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case '>': // A의 차수 > B의 차수
			attach(terms[As].expon, terms[As].expon);
			As++;
			break;
		case '=': // A의 차수 = B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++;
			Bs++;
			break;
		case '<': // A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		}
		// A의 나머지 항들을 이동함
		for (; As <= Ae; As++)
			attach(terms[As].coef, terms[As].expon);
		// B의 나머지 항들을 이동함
		for (; Bs <= Be; Bs++)
			attach(terms[Bs].coef, terms[Bs].expon);
		*Ce = avail - 1;
	}
}

int main()
{
	int Cs, Ce;

	poly_add2(0, 2, 3, 5, &Cs, &Ce);

	return 0;
}  */

// 희소행럴 :대부분의 항들이 0인 배열
// 2-(1) 희소행렬

/*
#include <stdio.h>
#define ROWS 3 // 행의 개수
#define COLS 3 // 열의 개수

// 희소 행렬 덧셈 함수
void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) // C = A + B
{
	int r, c;
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			C[r][c] = A[r][c] + B[r][c];
	}
}

int main()
{
	int array1[ROWS][COLS] = { { 2, 3, 0},
							   { 8, 9 ,1},
							   { 7, 0, 5} };
	int array2[ROWS][COLS] = { { 1, 0, 0},
							   { 1, 0, 0},
							   { 1, 0, 0} };
	int array3[ROWS][COLS];

	sparse_matrix_add1(array1, array2, array3);

	return 0;
}  */

// 2-(2) 희소행렬 - 0이 아닌 요소들만 저장
/*
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct
{
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix
{
	element data[MAX_TERMS];
	int rows; // 행의 개수
	int cols; // 열의 개수
	int terms; // 항의 개수
} SparseMatrix;

// 희소 행렬 덧셈 함수
// C = A + B
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b)
{
	SparseMatrix c;
	int ca = 0, cb = 0, cc = 0; // 각 배열의 항목을 가리키는 인덱스

	// 배열 a와 배열 b의 크기가 같은지를 확인
	if (a.rows != b.rows || a.cols != b.cols)
	{
		fprintf(stderr, "희소행렬 크기에러\n");
		exit(1);
	}
	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;

	while (ca < a.terms && cb < b.terms)
	{
		// 각 항목의 순차적인 번호를 계산한다.
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col;
		if (inda < indb)
		{
			// a 배열 항목이 앞에 있으면
			c.data[cc++] = a.data[ca++];
		}
		else if (inda == indb)
		{
			// a와 b가 같은 위치
			if ((a.data[ca].value + b.data[cb].value) != 0)
			{
				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}
			else
			{
				ca++;
				cb++;
			}
		}
		else
		{
			// b 배열 항목이 앞에 있음
			c.data[cc++] = b.data[cb++];
		}
	}
	// 배열 a나 b에 남아 있는 항들을 배열 c로 옮긴다.
	for (; ca < a.terms;)
		c.data[cc++] = a.data[ca++];
	for (; cb < b.terms;)
		c.data[cc++] = b.data[cb++];

	c.terms = cc;

	return c;
}

int main()
{
	SparseMatrix m1 = { { { 1, 1, 5 }, { 2, 2, 9 } }, 3, 3, 2 };
	SparseMatrix m2 = { { { 0, 0, 5 }, { 2, 2, 9 } }, 3, 3, 2 };
	SparseMatrix m3;

	m3 = sparse_matrix_add2(m1, m2);

	return 0;
} */

// 동적메모리

/* #include <stdio.h>

struct Example {
	int number;
	char name[10];
};

void main() {
	struct Example* p;

	p = (struct Example*)malloc(2 * sizeof(struct Example));
	if (p == NULL) {
		fpinrtf(stderr, "can't allocate memory\n");
		exit(1);
	}
	p->number = 1;
	strcpy(p->name, "Park");
	(p + 1)->number = 2;
	strcpy((p + 1)->name, "Kim");
	free(p);
} */

/* #include <stdio.h>

void foo(int a)
{
	printf("foo : %d\n", a);
}

int main()
{
	// f는 함수의 주소를 담는 포인터 타입이다.
	void(*f)(int);

	f = foo;
	f(10); // = foo(10)
	(*f)(10); // = f(10)

	return 0;
} */