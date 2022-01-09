#include <stdio.h>
#include <string.h>

/** 마지막 길이 반환 함수 ***/
int Endlen(int* arr)
{
int count = 0;
for(int i = 0; i < 100; i++){
    if(arr[i] != '\0'){
        count += 1;
        }
    else if(arr[i] == '\0'){
        break;
        }
    }
return count;
}

/**  데이터 출력 함수 ***/
void Output(int* arr)
{
for(int i = 0; i < 100; i++){
    if(arr[i] != '\0'){
        printf("%d ", arr[i]);
        }
    else if(arr[i] == '\0'){
        printf("\n");
        break;
        }
    }
}

/**  데이터 삽입 함수 ***/
void Insert(int* arr, int data)
{
arr[Endlen(arr)] = data;
}

/**  데이터 조회 함수 ***/
int Search(int* arr, int target)
{
int count = 0;
for(int i = 0; i < 100; i++){
    if(arr[i] != target){
        count += 1;
        }
    else if(arr[i] == target){
        break;
        }
    }
return count;
}

/**  데이터 중복 조회 함수 ***/
void DSearch(int* arr, int target)
{
int c = 0;
for(int i = 0; i<100; i++){
    if(arr[i] != target){
        c += 1;
        }
    else if(arr[i] == target){
        printf("%d 의 index : %d\n", target, c);
        c += 1;
        }
    }
}

/**  데이터 삭제 함수 ***/
int Remove(int* arr, int target)
{
int i = 0;
for(; i < 100; i++){
    if(arr[i] == target){
        arr[i] = '\0';
        break;
        }
    }
for(; i < 100; i++){
    arr[i] = arr[i+1];

    if(arr[i] == '\0'){
        break;
        }
    }
}

/** 데이터 중복 삭제 함수 **/
int DRemove(int* arr, int target)
{
for(int i = 0; i < 100; i++){
    Remove(arr, target);
    }
}



void main() {
    /*** 데이터 저장 배열 정의***/
    int Array[100] = { 0 };
    int n1 = 0;
    int rm = 0;

    /*** 5개의 데이터 저장 ***/
    Insert(Array, 11);     Insert(Array, 11);
    Insert(Array, 22);     Insert(Array, 22);
    Insert(Array, 33);     Insert(Array, 33);

    /*** 저장된 데이터  출력 ***/
    Output(Array);

    /*** 저장된 데이터  조회 ***/
    printf("조회값 입력 : ");
    scanf("%d", &n1);
    printf("입력한 데이터의 index : %d\n", Search(Array, n1));
    
    /*** 중복 데이터  조회 ***/
    DSearch(Array, n1);
    printf("\n");

    /*** 데이터  삭제 ***/
    printf("삭제값 입력 : ");
    scanf("%d", &rm);
    Remove(Array, rm);
    Output(Array);
    printf("\n");

    /*** 중복 데이터  삭제 ***/
    printf("중복 데이터 삭제값 입력 : ");
    scanf("%d", &rm);
    DRemove(Array, rm);
    Output(Array);
}