//此题只要用两个iterator即可， 当后一个iterator跑完时 前一个iterator还在字符数组里面， 我们即可判断NO
//我一开始两数组设置的很小 显示RW， 后来设置大了就AC了
#include <stdio.h>
#include <string.h>
#define test
static char s1[1000000];
static char s2[1000000];
int main()
{
#ifdef test
    freopen("data.in", "r", stdin);
    freopen("data.out","w", stdout);
#endif
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    while ((scanf("%s%s", s1, s2)) == 2){
        int i = 0, j = 0;
        while(s2[j] != '\0'){
            if (s2[j] == s1[i])
                i++;
            j++;
        }
        if (s1[i] == '\0')
            printf("Yes\n");
        else
            printf("No\n");
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
    }
}
