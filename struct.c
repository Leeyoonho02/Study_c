// 1. 이름은 grade
// 2. 멤버변수는 이름, 나이, 학번, 국,영,수 ... ,평균
// 3. 각 멤버변수의 자료형은 적절한것으로 알아서 생각해서 만들기
#include <stdio.h>

struct grade
{
    char name[50];
    int stu_id;
    int score_KOR;
    int score_ENG;
    int score_MATH;
    int score_SCI;
    float score_AVG;
};

int main()
{
struct grade g = {};

printf("put your name : ");
scanf("%s", &g.name);
printf("put your student id : ", g.name);
scanf("%d", &g.stu_id);
printf("put your KOR score : ", g.name, g.stu_id);
scanf("%d", &g.score_KOR);
printf("put your ENG score : ");
scanf("%d", &g.score_ENG);
printf("put your MATH score : ");
scanf("%d", &g.score_MATH);
printf("put your SCI score : ");
scanf("%d", &g.score_SCI);

g.score_AVG = (float)(g.score_KOR+g.score_ENG+g.score_MATH+g.score_SCI)/4;

printf("\nWelcome %s(%d)!\n", g.name, g.stu_id);
printf("\n[%s's score list]\n\nKOR : %d\nENG : %d\nMATH : %d\nSCI : %d\naverage : %.2f\n", g.name, g.score_KOR, g.score_ENG, g.score_MATH, g.score_SCI, g.score_AVG);

return 0;
}