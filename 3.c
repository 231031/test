#include <stdio.h>

int main() {
    float mark[20][6];
    //จองอาเรย์มิติที่สองไว้ 6 ช่องเพราะใช้ช่องที่ 6 เป็นผลเฉลี่ยของคะแนนของนักเรียนแต่ละคน จะได้ไม่ต้อง for loop 2 รอบเพื่อรวมคะแนน
    for (int i=0;i<20;i++) {
        for (int j=0;j<5;j++) {
            scanf("%f",&mark[i][j]);
            mark[i][5] += mark[i][j];
        }
    }
    int temp = 0;
    for(int i=0;i<20;i++) {
        mark[i][5] = mark[i][5]/5;
        if (mark[i][5] < 50) {
            temp++;
        }
    }
    printf("%d",temp);
    return 0;
}
