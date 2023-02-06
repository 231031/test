#include<stdio.h>

void pointArray()
{

}

int main()
{
    int num[5] = {0,1,2,3,4};
    printf("%p %p %p\n", num, &num, &num[0]);
    
}