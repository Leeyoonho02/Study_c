#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode; 

// 리스트의 시작
listNode* L = NULL;	//전역변수
int N, i = 0; // 노드 개수 카운트용 변수

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList() {
    listNode * cur = L;
    listNode * next = cur->link;

    while(next != NULL){
        free(cur);
        cur = next;
        next = cur->link;
    }
    L = NULL;
}

// 연결 리스트를 순서대로 출력하는 연산
void printList() {
    listNode * cur = L;
    if(cur == NULL){
        printf("노드가 존재하지 않습니다.");
    }
    else{
        while(cur != NULL){
            printf("%s ", cur->data);
            cur = cur->link;
        }
    }
	printf("\n%d 개의 노드가 있습니다.", N);
}

// 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(char* x) {

    listNode * cur = L;

 	for(i = 1; i<=N; i++){
        if(strcmp(cur->data,x)){
            cur = cur->link;
        }
        else{
            return cur;
        }
    }
    return NULL;
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(char* x) {
    listNode * node = (listNode *)malloc(sizeof(listNode));
    
    if (node == NULL){
        exit(1);
    }

    strcpy(node->data, x);

    if (L == NULL){
        L = node;
    }

    else{
        node->link = L;
        L = node;
    }
	N += 1;
}

// 노드 사이에 노드를 삽입하는 연산
void insertMiddleNode(listNode* pre, char* x) {
	listNode * node = (listNode *)malloc(sizeof(listNode));
	if (node == NULL){
        exit(1);
    }

	strcpy(node->data, x);

	if (L == NULL){
       	L = node;
   	}
    else{
		listNode * cur = L;
		while(cur->link != NULL){
			if(cur == pre){
				node->link = cur->link;
				cur->link = node;
				break;
			}
			cur = cur->link;
		}
    }
	N += 1;
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(char* x) {
    listNode * node = (listNode *)malloc(sizeof(listNode));

    if (node == NULL){
        exit(1);
    }

    strcpy(node->data, x);

    if (L == NULL){
        L = node;
    }
    else{
        listNode * cur = L;

        while(cur->link != NULL){
            cur = cur->link;
        }
        cur->link = node;
    }
	N += 1;
}

// 리스트에서 노드 p를 삭제하는 연산
void deleteNode(listNode* p) {
	//1 삭제전 해당 데이터 존재유무 조회
	//2 삭제 위치가 처음인경우
	//3 삭제 위치가 처음이아닌경우(마지막이거나 중간노드인경우)
	//3-1 삭제 위치가 마지막인경우(삭제 이전노드의 link에 NULL 대입 후 삭제노드 free)
	//3-2 삭제 위치가 중간노드인경우(삭제 이전노드의 link에 삭제할 노드의 link값 저장 후 삭제노드 free)
	listNode * cur = L;
	listNode * pre;
	for(i = 1; i<=N; i++){
        if(cur != p){
			pre = cur;
            cur = cur->link;
        }
        else{
            if(i == 1){ 				// 삭제 위치가 처음인 경우
				L = cur->link;
			}
			else if(i == N){		    // 삭제 위치가 마지막인 경우
				pre->link = NULL;
			}			
			else{ 						// 삭제 위치가 중간인 경우
				pre->link = cur->link;
			}
			free(cur);
			break;
        }
    }
	N -= 1;
}

// 메인 함수
int main() {
	listNode* p;
	L = NULL;     //공백 리스트 생성 

	// ---------------------------------------------
	// 데이터 삽입(첫노드)
	// ---------------------------------------------

	printf("----------(1) 첫노드에 삽입 [월][수] ----------\n");
	insertFirstNode("수");
	insertFirstNode("월");
	printList();
	printf("\n");

	// ---------------------------------------------
	// 데이터 삽입(끝노드)
	// ---------------------------------------------
	printf("\n----------(2) 마지막 노드에 삽입 [목][토][일] ----------\n");
	insertLastNode("목");
	insertLastNode("토");
	insertLastNode("일");
	printList();
	printf("\n");

	// ---------------------------------------------
// 데이터 탐색
// ---------------------------------------------
	printf("\n----------(3) 리스트에서 [목] 노드 탐색하기! ----------\n");
	p = searchNode("목");
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("[%s]를 찾았습니다.\n", p->data);

	printf("\n----------(4) 리스트에서 [금] 노드 탐색하기!----------\n");
	p = searchNode("금");
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("[%s]를 찾았습니다.\n", p->data);

	printf("\n----------(+) 리스트에서 [일] 노드 탐색하기! ----------\n");
	p = searchNode("일");
	if (p == NULL)
		printf("찾는 데이터가 없습니다.\n");
	else
		printf("[%s]를 찾았습니다.\n", p->data);	

	// ---------------------------------------------
	// 데이터 삽입 (중간 노드)
	// ---------------------------------------------
	printf("\n----------(5) 리스트의 [목] 뒤에 [금] 노드 삽입하기!----------\n");
	p = searchNode("목");
	insertMiddleNode(p, "금");
	printList();
	printf("\n");

	// ---------------------------------------------
	// 데이터 삭제
	// ---------------------------------------------
	printf("\n----------(6) 리스트에서 [일]노드 삭제하기!----------\n");
	p = searchNode("일");		// 삭제할 노드 위치 p를 찾음
	deleteNode(p);				// 포인터 p 노드 삭제
	printList();
	printf("\n");
	
	printf("\n----------(7) 리스트에서 [월]노드 삭제하기!----------\n");
	p = searchNode("월");
	deleteNode(p);
	printList();
	printf("\n");

	printf("\n----------(8) 리스트에서 [목]노드 삭제하기!----------\n");
	p = searchNode("목");
	deleteNode(p);
	printList();
	printf("\n");

	freeLinkedList();               //리스트 메모리 해제
	return 0;
}