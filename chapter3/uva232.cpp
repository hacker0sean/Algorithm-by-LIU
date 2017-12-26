#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    char s[20][20];
    int x[20][20];
    int a, b;
    int times = 1;
    int flag = 0;
    while(1)
    {
        int number = 1;
        memset(x, 0, sizeof(x));
        memset(s, 0, sizeof(s));
        scanf("%d%d", &a, &b);
        if (a == 0)
            break;
                if (flag == 0)
        {
            flag = 1;
        }
        else
        {
            printf("\n");
        }
        printf("puzzle #%d:\n", times++);
        for (int i = 0; i < a; i++)
        {
            scanf("%s", s[i]);
        }
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
            {
                if (i == 0 || j == 0)
                {
                    if (s[i][j] != '*')
                        x[i][j] = number++;
                }
                else if ((s[i-1][j] == '*' || s[i][j-1] == '*') && s[i][j] != '*')
                    x[i][j] = number++;
            }
/*        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
                {
                    printf("%d ",x[i][j]);
                }
            printf("\n");

        }
*/
           printf("Across\n");
            for (int i = 0; i < a; i++)
                for (int j = 0; j < b; j++)
                {
                    if(x[i][j] != 0)
                    {
                        printf("%3d.", x[i][j]);
                        while (s[i][j] != '*' && j != b)
                        {
                            printf("%c", s[i][j]);
                            j++;
                        }
                        printf("\n");
                    }
                }
            printf("Down\n");
            for (int i = 0; i < a; i++)
                for (int j = 0; j < b; j++)
                {
                    if(x[i][j] != 0)
                    {
                        int temp = i;
                        printf("%3d.", x[i][j]);
                        while (s[i][j] != '*' && i != a)
                        {
                            printf("%c", s[i][j]);
                            x[i][j] = 0;
                            i++;
                        }
                        i = temp;
                        printf("\n");
                    }
                }
    }
}
