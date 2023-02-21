#include <stdio.h>

int main() {
    int m,n;
    scanf("%d %d",&m,&n);
    int mtx[m][n];
    for (int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&mtx[i][j]);
        }
    }

    int count1 = 0; //xบน
    int count2 = 0; //yขวา
    int count3 = 0; //xล่าง
    int count4 = 0; //yซ้าย
    int x = 0;

    while (x != m*n) {
        for (int i=0;i<n;i++) {
            printf("%d ",mtx[count1][i+count1]);
            x++;
            // mtx[count1][i+count1] = 12345;
            if(i+count1 == n-1-count1) {
                break;
            }
        }


        if(x == m*n) {
                break;
            }

        count1++;

        for (int i=0;i<m;i++) {
            printf("%d ",mtx[i+count2+1][n-count2-1]);
            x++;
            // mtx[i+count2+1][n-count2-1] = 12345;
            if(i+count2+1 == m-1-count2) {
                break;
            }
        }


        if(x == m*n) {
                break;
            }

        count2++;

        for (int i=1;i<n;i++) {
            printf("%d ",mtx[m-count3-1][n-i-1-count3]);
            x++;
            // mtx[m-count3-1][n-i-1-count3] = 12345;
            if(n-i-1-count3 == 0+count3) {
                break;
            }
        }

        if(x == m*n) {
                break;
            }


        count3++;

        for (int i=1;i<m;i++) {
            printf("%d ",mtx[m-i-1-count4][count4]);
            x++;
            // mtx[m-i-1-count4][count4] = 12345;
            if(m-i-1-count4 == 1+count4) {
                break;
            }
        }
        count4++;

        if(x == m*n) {
                break;
            }

    }
    return 0;
}