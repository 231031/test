#include <stdio.h>

int main() {
    double mark[21][5];
    //จองอาเรย์มิติแรกไว้ 21 ช่องเพราะใช้ช่องที่ 21 เป็นผลเฉลี่ยจะได้ไม่ต้องสร้างตัวแปรเพิ่มแล้ว for loop 2 รอบ
    int temp;
    for (int i=0;i<20;i++) {
        for (int j=0;j<5;j++) {
            scanf("%d",&temp);
            mark[i][j] = temp;
            mark[20][j] += mark[i][j]; 
        }
    }
    
    for(int i=0;i<5;i++) {
        mark[20][i] = mark[20][i]/20.0;
        if((int)((mark[20][i])*10)%10 == 0) {
            printf("%.0lf\n",mark[20][i]);
        }
        else if((int)((mark[20][i])*100)%10 == 0) {
            printf("%.1lf\n",mark[20][i]);
        }
        else {
            printf("%.2lf\n",mark[20][i]);
        }
    // คูณ 10 แล้ว mod ด้วย 10 เพื่อเช็คทศนิยม
    }
    return 0;
}