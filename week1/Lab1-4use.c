#include<stdio.h>
int main()
{
    int size; // ประกาศขนาดของ matrix
    scanf("%d",&size); // รับขนาดของ matrix 
    int matrix[size][size];
    for(int i=0;i<size;i++) //Loop รับค่าของ matrix
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int sum=0; // ประกาศตัวแปร sum เพื่อเก็บผลรวมของ diagonal
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j)
            {
                sum+=matrix[i][j]; //ในแนวแทยงมุม ตำแหน่งที่ i และ j เท่ากัน จึงนำมาบวกกัน
            }
        }
    }
    printf("%d",sum);
} 