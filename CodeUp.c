#include <stdio.h>      

int main(){
int w, h, n, l, d, x, y, i, j;
int a[100][100];

scanf("%d%d%d", &w, &h, &n);

for(i=0; i<n; i++){
    scanf("%d%d%d%d", &l, &d, &x, &y);
    if(d == 1){
        for(j=x; j<x+l; j++){
            a[j][y] = 1;
        }
    }
    else{
        for(j=y; j<y+l; j++){
            a[x][j] = 1;
        }
    }
}
for(i=1; i<=w; i++){
    for(j=1; j<=h; j++){
        printf("%d ", a[i][j]);
    }
    printf("\n");
}

return 0;
}
