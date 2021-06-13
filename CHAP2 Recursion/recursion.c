// 순환 : 순환 호출 이용
// - 모든 순환은 반복으로 바꾸어 작성가능

//1.팩토리얼

/*int factorial_iter(int n) {
	int k, v = 1;
	for (k = n; k > 0;k--)
		v = v * k;
	return(v);
} */

//2. 피보나치 수열

/*fib_iter(int n) {
	if (n < 2) return n;
	else {
		int i, tmp, current = 1, last = 0, ;
		for (i = 2; i < n; i++) {
			tmp = current;
			current += last;
			last = tmp;
		}
	}
 }
 */

 // 3. 하노이탑

 /* #include <stdio.h>

 void hanoi_tower(int n, char from, char tmp, char to) {
	 if (n == 1) printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	 else {
		 hanoi_tower(n - 1, from, to, tmp);
			 printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
		 hanoi_tower(n - 1, tmp, from, to);
	 }
 }


 void main() {
	 hanoi_tower(4, 'A', 'B', 'C');
 }
 */

 // Exercise
 /* #include <stdio.h>
 int rescrusive(int n)
 {
 printf("%d\n", n);
 if (n < 1) return 2;
 else return (2 * rescrusive(n - 1) + 1);
 }

 int main(void) {
	 rescrusive(5);
 } */