#include <stdio.h>
#define maxn 10000          // error 1 : the big array should be annoucced out of the function !! we can't set maxn to a small number
int main()
{
    char s[maxn];
    scanf("%s", s);
    int tot = 0;
    const int a = strlen(s);    //error 2 : the strlen function should not appear in the loop, it will be executed many times
    for (int i = 0; i < a; i++)
    {
        if (s[i] == '1')        //error 3 : s[i] is a character while 1 is a int, they can never equal.
            tot++;
    }
    printf("%d\n",tot);
}
