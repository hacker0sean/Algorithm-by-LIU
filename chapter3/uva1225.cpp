#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[10000000];

int main()
{
    int a[10];
    int T;
    cin >> T;
    int flag;
    while (T--)
    {
        flag = 0;
        int number;
        cin >> number;
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= number; i++)
        {
            char temp[10000];
            sprintf(temp, "%d", i);
            strcat(s, temp);
        }
        int length = strlen(s);
        for (int i = 0; i < length; i++)
        {
            a[s[i] - '0']++;
        }
        for (int i = 0; i < 10; i++)
        if (flag == 0)
        {
            flag = 1;
            printf("%d", a[i]);
        }
        else
            printf(" %d", a[i]);

        printf("\n");
    }
    return 0;
}
