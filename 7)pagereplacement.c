#include <stdio.h>
#include <stdlib.h>

void FIFO(char s[], char F[], int l, int f) {
    int i, j = 0, k, flag;
    printf("PAGE\tFRAMES\tFAULTS");
    for (i = 0; i < l; i++) {
        flag = 0;
        for (k = 0; k < f; k++)
            if (F[k] == s[i])
                flag = 1;
        printf("\n%c\t", s[i]);
        if (flag == 0) {
            F[j++] = s[i];
            printf("%s", F);
            printf("\tPage Fault");
        } else {
            printf("%s", F);
            printf("\tPage Hit");
        }
        if (j == f)
            j = 0;
    }
}

void LRU(char s[], char F[], int l, int f) {
    int i, j = 0, k, m, flag, top = 0;
    printf("\nPAGE\tFRAMES\tFAULTS");
    for (i = 0; i < l; i++) {
        flag = 0;
        for (k = 0; k < f; k++)
            if (F[k] == s[i])
                flag = 1;
        printf("\n%c\t", s[i]);
        if (j != f && flag != 1) {
            F[top] = s[i];
            if (++j != f)
                top++;
        } else {
            if (flag != 1) {
                for (k = 0; k < top; k++)
                    F[k] = F[k + 1];
                F[top] = s[i];
            } else {
                for (m = k; m < top; m++)
                    F[m] = F[m + 1];
                F[top] = s[i];
            }
        }
        printf("%s", F);
        if (flag == 0)
            printf("\tPage Fault");
        else
            printf("\tPage Hit");
    }
}

int main() {
    int ch, i, l, f;
    char F[10], s[25];
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    printf("Enter the length of the string: ");
    scanf("%d", &l);

    printf("Enter the string: ");
    scanf("%s", s);

    while (1) {
        printf("\nEnter:\n1:FIFO\n2:LRU\n3:EXIT\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                for (i = 0; i < f; i++)
                    F[i] = -1;
                FIFO(s, F, l, f);
                break;
            case 2:
                for (i = 0; i < f; i++)
                    F[i] = -1;
                LRU(s, F, l, f);
                break;
            case 3:
                exit(0);
        }
    }

    return 0;
}
