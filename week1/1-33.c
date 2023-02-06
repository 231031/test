#include <stdio.h>

int changeint(int n, int *a, int *b) {
    *a = *b;
    return 0;
}

int main() {
    int n;
    scanf("%d",&n);

    int arr[n],temparr[n];
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        temparr[i] = arr[i];
    }

    int temp;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (temparr[j] > temparr[j+1]) {
                int tmp = temparr[j];
                temparr[j] = temparr[j+1];
                temparr[j+1] = tmp;
            }
        }
    }

    for (int i=0;i<n;i++) {
        // printf("%d",temparr[i]);
        if (arr[i] == temparr[1]) {
            changeint(n,&arr[i],&temparr[n-2]);
        }
        else if (arr[i] == temparr[n-2]) {
            changeint(n,&arr[i],&temparr[1]);
        }
        printf("%d ",arr[i]);
    }

    return 0;
}
