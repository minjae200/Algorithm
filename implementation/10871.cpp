#include <stdio.h>

int main(void)
{
    int N, X;
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        if (data < X) {
            printf("%d ", data);
        }
    }
    return 0;
}