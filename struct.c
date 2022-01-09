#include <stdio.h>

struct grade
{
    int stu_id;
    int score_KOR;
    int score_ENG;
    int score_MATH;
    int score_SCI;
    float score_AVG;
};

struct student
{
    char name[50];
    int number;
    struct grade g;
};

int main()
{
struct student s;
struct grade g;

printf("Enter your name : ");
scanf("%s", &s.name);
printf("Enter your student id : ");
scanf("%d", &s.g.stu_id);

printf("Enter your KOR score : ");
scanf("%d", &s.g.score_KOR);
printf("Enter your ENG score : ");
scanf("%d", &s.g.score_ENG);
printf("Enter your MATH score : ");
scanf("%d", &s.g.score_MATH);
printf("Enter your SCI score : ");
scanf("%d", &s.g.score_SCI);

s.g.score_AVG = (float)(s.g.score_KOR+s.g.score_ENG+s.g.score_MATH+s.g.score_SCI)/4;

printf("\nWelcome %s(%06d)!\n", s.name, s.g.stu_id);
printf("\n[%s's score list]\n\nKOR : %02d\nENG : %02d\nMATH : %02d\nSCI : %02d\naverage : %.2f\n", s.name, s.g.score_KOR, s.g.score_ENG, s.g.score_MATH, s.g.score_SCI, s.g.score_AVG);

return 0;
}