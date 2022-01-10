#include <stdio.h>
#include <stdlib.h> // 동적메모리관리에 필요함.
#include <string.h> // 문자열 관련에 필요함.

//==================================================================//

// 리스트 노드 구조체 선언
typedef struct studentNode{
    char name[20];
    int stud_id;
    float stud_score;
    struct studentNode * link;
}Node;

// 전역변수들
Node * L = NULL; // 헤더
int N, i; // 노드 개수 카운트

//==================================================================//

// 학생 추가 함수 (가나다순 자동 배열 맞추기 시스템 구축하기!)
void insertFirst(char* a, int b, float c){  

    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        exit(1);
    }
    strcpy(node->name, a);
    node->stud_id = b;
    node->stud_score = c;

    if(L == NULL){
        L = node;
    }
    else{
        node->link = L;
        L = node;
    }
    N++;
}

void insertMiddle(Node* x, char* a, int b, float c){

    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        exit(1);
    }
    strcpy(node->name, a);
    node->stud_id = b;
    node->stud_score = c;

    

    N++;
}

void insertLast(char* a, int b, float c){   

    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        exit(1);
    }
    strcpy(node->name, a);
    node->stud_id = b;
    node->stud_score = c;

    if(L == NULL){
        L = node;
    }
    else{
        Node* curr = L;

        while(curr->link != NULL){
            curr = curr->link;
        }
        curr->link = node;
    }
    N++;
}

void insertStudent(){
    char a[20]; // 이름 입력 변수
    int b; // 학번 입력 변수
    float c; // 학점 입력 변수
    
    printf("\n추가 대상 학생의 이름을 입력하세요 : ");
    scanf("%s", a);
    printf("\n추가 대상 학생의 학번을 입력하세요 : ");
    scanf("%d", &b);
    Return :
    printf("\n추가 대상 학생의 학점을 입력하세요 : ");
    scanf("%f", &c);
    if(!(c>=0 && c<=4.5)){
        printf("\n잘못된 범위입니다.\n");
        goto Return;
    }
    insertFirst(a, b, c);
}

// 학생 제거 함수
void deleteStudent(char* a){    
    Node* curr = L;
    Node* pre;
    for(i=1; i<=N; i++){
        if(strcmp(curr->name, a)){
            pre = curr;
            curr = curr->link;
        }
        else{
            if(i == 1){
                L = curr->link;
            }
            else if(i == N){
                pre->link = NULL;
            }
            else{
                pre->link = curr->link;
            }
            free(curr);
            N--;
            break;
        }
    }
    if(curr == NULL){
        printf("\n해당 학생이 없습니다.\n");
    }
}

// 학생 조회 함수
void searchStudent(char* a){  
  
    Node* curr = L;
    while(curr != NULL){
        if(strcmp(curr->name, a)){
            curr = curr->link;
        }
        else{
            printf("\n[%s]\n학번 : %06d\n평균 학점 : %.1f\n", curr->name, curr->stud_id, curr->stud_score);
            break;
        }
    }
    if(curr == NULL){
        printf("해당 학생이 없습니다.");
    }
}

// 리스트 전체 출력 함수
void printAllStudent(){  
    if(L == NULL){
        printf("\n학생이 하나도 없습니다.\n");
    }
    else{
        Node* curr = L;
        while(curr != NULL){
            printf("\n[%s]\n학번 : %06d\n평균 학점 : %.1f\n", curr->name, curr->stud_id, curr->stud_score);
            curr = curr->link;
        }
    }
}

// 리스트 초기화 함수
void deleteAllStudent(){   
   if(L == NULL){
        printf("\n학생이 하나도 없습니다.\n");
    }
    else{
        Node* curr = L;
        Node* next = curr->link;
        while(next != NULL){
            free(curr);
            curr = next;
            next = curr->link;
        }
        L = NULL;
        N = 0;
    }
}

//==================================================================//

// 메뉴 선택 함수
void menuSelect(){
        printf("\n\033[0;33m[1] 학생 추가\n[2] 학생 제거\n[3] 학생 조회\n[4] 학생 리스트 전체 출력\n[5] 학생 리스트 초기화\n[6] 프로그램 종료\033[0;37m\n");
    printf("\n원하는 항목의 번호를 입력하세요 : ");
    int n;
    char a[20];
    scanf("%d", &n);

    switch (n){
        case 1 :
            insertStudent();
            menuSelect();
            break;
        case 2 :
            printf("\n제거 대상 학생의 이름을 입력하세요 : ");
            scanf("%s", a);
            deleteStudent(a);
            menuSelect();
            break;
        case 3 :
            printf("\n조회 대상 학생의 이름을 입력하세요 : ");
            scanf("%s", a);
            searchStudent(a);
            menuSelect();
            break;
        case 4 :
            printAllStudent();
            menuSelect();
            break;
        case 5 :
            deleteAllStudent();
            menuSelect();
            break;
        case 6 :
            deleteAllStudent();
            break;
        default :
            printf("\n잘못된 입력입니다.\n");
            menuSelect();
            break ;
    }
}

// 메인 함수
void main(){   
    printf("\n\033[0;32m[학생 관리 프로그램]\033[0;37m\n");
    menuSelect();
    printf("\n프로그램을 종료합니다.\n");
}
