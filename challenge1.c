#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    double x1, x2;
    double root;

    printf("Enter a,b,c in order:");
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("%lf %lf %lf\n",a,b,c);
    root = (b*b) - (4*a*c);
    /*
    if (root < 0)
    {
        printf("error\n");
        return 0;

    }*/
    x1 = ((-b) + sqrt(root))/(2*a);
    x2 = ((-b) - sqrt(root))/(2*a);

    printf("Result 1: %lf\n", x1);
    printf("Result 2: %lf\n", x2);
    return 0;
}