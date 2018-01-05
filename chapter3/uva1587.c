//这道题花了一些时间， 主要过程分为两部， 第一部是判断是能组成三对数， 第二部是判断这三对数能否构成矩形， 第二部判断的时候有顺序要求， 完全讨论的话
//有六种情况， 但根据长方体的对称性， 只需要考虑两种情况即可， 自己画图的话很明显可以看出。 代码写的比较丑， 呵呵。
#include <stdio.h>
#include <string.h>

#define testc
typedef struct {
    int a;
    int b;
} square;
square sq[3];
int s[6][2];

int testa(int *a, int *b);

int testb(int a, int b, int *c);


int main() {
#ifdef test
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    memset(s, 0, sizeof(s));
    while ((scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &s[0][0], &s[0][1], &s[1][0], &s[1][1], &s[2][0], &s[2][1], \
                      &s[3][0], &s[3][1], &s[4][0], &s[4][1], &s[5][0], &s[5][1])) != EOF) {
        int m[6] = {0};
        int flag = 1;
        int h = 0;
        for (int i = 0; i < 6; i++) {
            if (m[i] == 1)
                continue;
            for (int j = i + 1; j < 6; j++) {
                if (m[j] == 1)
                    continue;
                if (testa(&s[i][0], &s[j][0])) {
                    m[i] = m[j] = 1;
                    sq[h].a = s[i][0];
                    sq[h].b = s[i][1];
                    h++;
                    break;
                }
            }
        }
        for (int i = 0; i < 6; i++) {
            if (m[i] == 0) {
                flag = 0;
                printf("IMPOSSIBLE\n");
                break;
            }
        }
        if (flag == 0)
            continue;
        flag = 1;
        memset(m, 0, sizeof(m));
        testb(0, 1, m);
        testb(0, 2, m);
        testb(1, 2, m);
        for (int i = 0; i < 6; i++) {
            if (m[i] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf("POSSIBLE\n");
            continue;
        }
        flag = 1;
        memset(m, 0, sizeof(m));
        testb(0, 2, m);
        testb(0, 1, m);
        testb(1, 2, m);
        for (int i = 0; i < 6; i++) {
            if (m[i] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf("POSSIBLE\n");
            continue;
        }
        printf("IMPOSSIBLE\n");
    }
}

int testb(int a, int b, int *m) {
    if (sq[a].a == sq[b].a && m[2 * a] != 1 && m[2 * b] != 1)
        m[2 * a] = m[2 * b] = 1;
    else if (sq[a].a == sq[b].b && m[2 * a] != 1 && m[2 * b + 1] != 1)
        m[2 * a] = m[2 * b + 1] = 1;
    else if (sq[a].b == sq[b].a && m[2 * a + 1] != 1 && m[2 * b] != 1)
        m[2 * a + 1] = m[2 * b] = 1;
    else if (sq[a].b == sq[b].b && m[2 * a + 1] != 1 && m[2 * b + 1] != 1)
        m[2 * a + 1] = m[2 * b + 1] = 1;
}

int testa(int *a, int *b) {
    if (a[0] == b[0] && a[1] == b[1] || a[0] == b[1] && a[1] == b[0])
        return 1;
    return 0;
}
