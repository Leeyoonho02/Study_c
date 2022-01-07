#include <stdio.h>
int main(){
int a=0, b=0, c=0;
int *p = &b;
printf("int *p = &b\na:%d b:%d c:%d\np[0]:%d p[1]:%d\n", a, b, c, p[0], p[1]);
p[0] = 2;
p[1] = 3;
*(p-1) = 1;
printf("a:%d b:%d c:%d\n", a, b, c);
printf("a:%lld b:%lld c:%lld\n", &a, &b, &c);
}