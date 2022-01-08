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

printf("Enter your name : ");
scanf("%s", &g.name);
printf("Enter your student id : ", g.name); //잘 몰라서 일단 6자리 생년월일로..
scanf("%d", &g.stu_id);
printf("Enter your KOR score : ", g.name, g.stu_id);
scanf("%d", &g.score_KOR);
printf("Enter your ENG score : ");
scanf("%d", &g.score_ENG);
printf("Enter your MATH score : ");
scanf("%d", &g.score_MATH);
printf("Enter your SCI score : ");
scanf("%d", &g.score_SCI);

g.score_AVG = (float)(g.score_KOR+g.score_ENG+g.score_MATH+g.score_SCI)/4;

printf("\nWelcome %s(%06d)!\n", g.name, g.stu_id);
printf("\n[%s's score list]\n\nKOR : %02d\nENG : %02d\nMATH : %02d\nSCI : %02d\naverage : %.2f\n", g.name, g.score_KOR, g.score_ENG, g.score_MATH, g.score_SCI, g.score_AVG);

return 0;
}