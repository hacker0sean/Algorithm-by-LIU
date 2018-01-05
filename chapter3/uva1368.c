#include <stdio.h>
#include <string.h>
#define testc
int main()
{
#ifdef test
    freopen("data.in", "r", stdin);
    freopen("data.out","w", stdout);
#endif
    int t;
    int m, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &m, &n);
        char s[m][n + 1];
        for (int i = 0; i < m; i++)
            scanf("%s", s[i]);
#ifdef test
        for (int i = 0; i < m; i++)
            printf("%s\n", s[i]);
#endif
        char result[n];
        int alph[4];
        int count = 0;
        for (int i = 0; i < n; i++){
            memset(alph, 0, sizeof(alph));
            for (int j = 0; j < m; j++){
                switch (s[j][i]){
                    case 'A':
                        alph[0]++;
                        break;
                    case 'C':
                        alph[1]++;
                        break;
                    case 'G' :
                        alph[2]++;
                        break;
                    case 'T' :
                        alph[3]++;
                        break;
                }
            }
            int max = 0;
            for (int k = 0; k < 4; k++){
                if (alph[k] > alph[max])
                    max = k;
            }
            switch (max){
                case 0:
                    result[i] = 'A';
                    break;
                case 1:
                    result[i] = 'C';
                    break;
                case 2:
                    result[i] = 'G';
                    break;
                case 3:
                    result[i] = 'T';
                    break;
            }
        }
        for (int i = 0; i < n; i++){
            printf("%c", result[i]);
            for (int j = 0; j < m; j++)
                if (result[i] != s[j][i])
                    count++;
        }
        printf("\n%d\n", count);
    }
}
