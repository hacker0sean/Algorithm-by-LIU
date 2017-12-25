#include <stdio.h>
#include <string.h>
char map[1000][1000];
char s[800];
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int m = 0, j = 0;
    int a = 0, b = 0;

    int times = 1;
    int flag1 = 0;
    while(1)
    {
        int error = 0;
        for (int i = 0; i < 5; i++)
        {
            char p;
            int flag = 1;
            for (int q = 0; q < 5; q++)
            {
                if ((p = getchar()) == '\n')
                    {
                        flag = 0;
                        map[i][q] = ' ';
                    }
                else
                    map[i][q] = p;
            }
            if (flag != 0)
                getchar();
        }
        if (map[0][0] == 'Z')
            break;
        if (flag1 == 0)
        {
            flag1 = 1;
            printf("Puzzle #%d:\n", times++);
        }
        else
        {
            printf("\nPuzzle #%d:\n", times++);
        }
        for (int i = 0; i < 5; i++)
          for (int q = 0; q < 5; q++)
          {
            if(map[i][q] == ' ')
            {
              a = i;
              b = q;
            }
          }
        m = 0;
        j = 0;
        char c;
        while ((c = getchar()) != '0')
        {
            if (c == 'A' || c == 'B' || c == 'L' || c == 'R' )
                s[m++] = c;
            else if (c != '\n')
                error = 1;
        }
        while (j < m)
        {
          switch(s[j++])
          {
            case 'A':
              if (a-1 < 0)
              {
                error = 1;
              }
              else
              {
              map[a][b] = map[a-1][b];
              map[a-1][b] = ' ';
              a = a-1;
              }
              break;
            case 'B':
              if (a+1 > 4)
              {
                error = 1;
              }
              else
              {
                map[a][b] = map[a+1][b];
                map[a+1][b] = ' ';
                a=a+1;
              }
                break;
            case 'L':
              if (b-1 < 0)
              {
                error = 1;
              }
              else
              {
              map[a][b] = map[a][b-1];
              map[a][b-1] = ' ';
              b=b-1;
              }
              break;
            case 'R':
              if (b+1 > 4)
              {
                error=1;
              }
              else
              {
                map[a][b] = map[a][b+1];
                map[a][b+1] = ' ';
                b=b+1;
              }
          }
          if (error == 1)
            break;
        }
        if (error == 1)
          printf("This puzzle has no final configuration.\n");
        else
        {
            for (int i = 0; i < 5; i++)
            {
                int k = 0;
                for (int j = 0; j < 5; j++)
                    if (k == 0)
                    {
                        k = 1;
                        printf("%c", map[i][j]);
                    }
                    else
                        printf(" %c", map[i][j]);
                printf("\n");
            }
        }
        getchar();
    }
}
