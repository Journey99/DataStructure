/*
< TREE - 트리 >
 : 계층적인 구조를 나타내는 자료구조 
   트리는 부모 - 자식 관계의 노드들로 이루어진다
   
   응용분야 ex) 계층적인 조직 표현, 컴퓨터 디스크의 디렉토리 구조, 인공지능에서의 결정트리(decision tree)

- 트리의 용어
  *노드 (node) : 트리의 구성요소
  * 루트 (root) : 부모가 없는 노드
  * 서브트리 : 하나의 노드와 그 노드들의 자손들로 이루어진 트리
  * 단말노드 : 자식이 없는 노드
  * 비단말노드 : 적어도 하나의 자식을 가지는 노드
  * 레벨 (level) : 트리의 각층의 번호
  * 높이 (height) : 트리의 최대 레벨
  * 차수 (degree) : 노드가 가지고 있는 자식 노드의 개수

- 트리의 종류
  *일반 트리 
  *이진 트리 : 모든 노드가 2개의 서브 트리를 가지고 있는 트리
      

- 이진 트리 (binary tree)
  : 이진트리의 노드에는 최대 2개까지의 자식 노드 존재
    모든 노드의 차수가 2 이하
    이진 트리에는 서브 트리간의 순서가 존재

  # 성질
    1) 노드의 개수가 n개이면 간선의 개수는 n-1
    2) 높이가 h인 이진트리의 경우, 최소 h개의 노드를 가지며 최대 2^h-1개의 노드를 가진다
    3) n개의 노드를 가지는 이진트리의 높이 최대 n 최소 log2(n+1)

  # 이진 트리의 분류
    * 포화 이진 트리 : 전체 노드의 개수 = 2^n -1
    * 완전 이진 트리 : 마지막레벨 제외하고는 포화 이진트리 / 왼쪽부터 오른쪽으로 노드가 순서대로 채워져 있다
    * 기타 이진 트리
   
  # 이진트리의 표현
    * 배열을 이용
    * 포인터를 이용

  # 부모와 자식 인덱스 관계
   1) 노드 i의 부모 노드 인덱스 =i/2
   2) 노드 i의 왼쪽 자식 노드 인덱스 = 2i
   3) 노드 i +1의 왼쪽 자식 노드 인덱스 = 2i + 1

  # 링크 표현법
     : 포인터를 이용하여 부모노드가 자식노드를 가리키게 하는 방법

     typedef struct TreeNode{
        int data;
        strcut TreeNode *left, *right;
    }TreeNode;

  # 이진 트리의 순회
    : 트리의 노드들을 체계적으로 방문하는 것
    1) 전위순회 : VLR   ex) 구조화된 문서출력
    2) 중위순회 : LVR   ex) 수식 트리
    3) 후위순회 ; LRV   ex) 디렉토리 용량 계산
    
  
  */