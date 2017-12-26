#include <stdio.h>
#include <string.h>
#define Ts
static int r[3005], u[3005], s[3005];
int main()
{
#ifdef T
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int m, n;
    while ((scanf("%d%d", &m, &n) != EOF))
    {
        int i;
        memset (u, 0, sizeof(u));
        int count = 0;
        int temp = m;
        r[count++] = m / n;
        m = m % n;
        while (!u[m] && m)
        {
            u[m] = count;
            s[count] = m;
            r[count++] = m * 10 / n;
            m = m * 10 % n;
        }
        printf("%d/%d = ", temp, n);
        printf("%d.",r[0]);
        for (i = 1; i < count && i <= 50; i++)
        {
            if (s[i] == m)
                printf("(%d", r[i]);
            else
                printf("%d", r[i]);
        }
        if (m == 0)
            printf("(0");
        if (i == 51)
            printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", !m ? 1 : count - u[m]);
    }
    return 0;
}
