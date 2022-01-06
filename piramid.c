#include <stdio.h>
int main()
{
int a;
scanf("%d", &a);
for(a; a != 0; a -= 1){
        for (int i = 1; i != (a+1); i += 1){
            printf("*");
        }
    printf("\n");
    }
return 0;
}