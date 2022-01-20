#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 동적메모리관리에 필요함.
#include <string.h> // 문자열 관련에 필요함.

//==================================================================//

// 리스트 노드 구조체 선언
typedef struct studentNode {
    char stud_name[10];
    int stud_id;
    float stud_score;
    struct Node* link;
}Node;

// 전역변수들
Node* L = NULL; // 헤더
int N = 0, i = 0; // 노드 개수 카운트

//==================================================================//

// 학생 추가 함수
void insertStudent() {
    char name[10] = ""; // 이름 입력 변수
    int id = 0; // 학번 입력 변수
    float score = 0; // 학점 입력 변수

    printf("\n추가 대상 학생의 이름을 입력하세요 : ");
    scanf("%s", name);

Return1:
    printf("\n추가 대상 학생의 학번을 입력하세요 : ");
    scanf("%d", &id);
    Node* curr = L;
    while (curr != NULL) {
        if (id == curr->stud_id) {
            printf("\n동일한 학번의 학생이 존재합니다.\n");
            goto Return1;
        }
        else {
            curr = curr->link;
        }
    }

Return2:
    printf("\n추가 대상 학생의 학점을 입력하세요 : ");
    scanf("%f", &score);
    if (!(score >= 0 && score <= 4.5)) {
        printf("\n잘못된 범위입니다.\n");
        goto Return2;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        exit(1);
    }
    strcpy(node->stud_name, name);
    node->stud_id = id;
    node->stud_score = score;
    node->link = NULL;

    if (L == NULL) {
        L = node;
    }
    else {
        Node* curr = L;
        Node* pre = NULL;
        for (i = 0; i < N; i++) {
            if (strcmp(node->stud_name, curr->stud_name) > 0) {
                pre = curr;
                curr = curr->link;
            }
            else if (strcmp(node->stud_name, curr->stud_name) <= 0) {
                if (i == 0) {
                    node->link = curr;
                    L = node;
                    break;
                }
                else {
                    node->link = curr;
                    pre->link = node;
                    break;
                }
            }
        }
        if (curr == NULL) {
            pre->link = node;
        }
    }
    N++;
}

// 학생 제거 함수
void deleteStudent(char* a) {
    Node* curr = L;
    Node* pre = NULL;
    for (i = 1; i <= N; i++) {
        if (strcmp(curr->stud_name, a)) {
            pre = curr;
            curr = curr->link;
        }
        else {
            if (i == 1) {
                L = curr->link;
            }
            else if (i == N) {
                pre->link = NULL;
            }
            else {
                pre->link = curr->link;
            }
            free(curr);
            N--;
            break;
        }
    }
    if (curr == NULL) {
        printf("\n해당 학생이 없습니다.\n");
    }
}

// 학생 조회 함수
void searchStudent(char* a) {

    Node* curr = L;
    for (i = 0; i < N; i++) {
        if (strcmp(curr->stud_name, a)) {
            curr = curr->link;
        }
        else {
            printf("\n[%s]\n학번 : %06d\n평균 학점 : %.1f\n\n", curr->stud_name, curr->stud_id, curr->stud_score);
            break;
        }
    }
    if (i == N) {
        printf("\n해당 학생이 없습니다.\n\n");
    }
}

// 리스트 전체 출력 함수
void printAllStudent() {
    if (L == NULL) {
        printf("\n학생이 하나도 없습니다.\n\n");
    }
    else {
        Node* curr = L;
        for (i = 0; i < N; i++) {
            printf("\n%p\n", curr);
            printf("\n[%s]\n학번 : %06d\n평균 학점 : %.1f\n", curr->stud_name, curr->stud_id, curr->stud_score);
            curr = curr->link;
        }
    }
}

// 리스트 초기화 함수
void deleteAllStudent() {
    if (L == NULL) {
        printf("\n학생이 하나도 없습니다.\n");
    }
    else {
        Node* curr = L;
        Node* pre = NULL;
        for (i = 0; i < N; i++) {
            pre = curr;
            curr = curr->link;
            free(pre);
        }
        L = NULL;
        N = 0;
    }
}

// 메인 함수
void main() {

    int n = 0;
    char a[20] = { 0 };
    printf("\n======================[학생 관리 프로그램]======================\n[1] 학생 추가\n[2] 학생 제거\n[3] 학생 조회\n[4] 학생 리스트 전체 출력\n[5] 학생 리스트 초기화\n[6] 프로그램 종료\n===============================================================\n");
    printf("\n원하는 항목의 번호를 입력하세요 : ");
    scanf("%d", &n);
    switch (n) {
    case 1:
        insertStudent();
        main();
        break;
    case 2:
        printf("\n제거 대상 학생의 이름을 입력하세요 : ");
        scanf("%s", a);
        deleteStudent(a);
        main();
        break;
    case 3:
        printf("\n조회 대상 학생의 이름을 입력하세요 : ");
        scanf("%s", a);
        searchStudent(a);
        main();
        break;
    case 4:
        printAllStudent();
        main();
        break;
    case 5:
        deleteAllStudent();
        main();
        break;
    case 6:
        deleteAllStudent();
        printf("\n프로그램을 종료합니다.\n");
        break;
    default:
        printf("\n잘못된 입력입니다.\n");
        main();
        break;
    }
}
