#include<stdio.h>
typedef struct{
    char name[16];
    int score;
} ST;

int com(void *s1, void *s2)
{
    int com;
    if ((((ST *)s1)->score) == (((ST*)s2)->score))
    {
        return 0;
    }
}
int main()
{
    
}