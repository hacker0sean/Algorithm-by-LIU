//#include <stdio.h>
//#include <cstring>
//int main()
//{
//    char s[100];
//    int T, length1, length2;
//    scanf("%d", &T);
//    getchar();
//    int flag = 0;
//    int flag2 = 0;
//    while (T--)
//    {
//        scanf("%s", s);
//        length1 = strlen(s);
//        for (int i = 1; i < length1; i++)
//        {
//            if (s[i] != s[0])
//                continue;
//            else
//            {
//                flag = 1;
//                length2 = i;
//                for (int j = i; j < length1; j = j + length2)
//                {
//                    if (flag == 0)
//                        break;
//                    for (int k = 0; k < i; k++)
//                        if (s[k] != s[j + k])
//                        {
//                            flag = 0;
//                            break;
//                        }
//                }
//            }
//            if (flag == 1)
//            {
//                if (flag2 == 0)
//                {
//                  flag2 = 1;
//                  printf("%d\n", length2);
//                  break;
//                }
//                else
//                {
//                  printf("\n%d\n", length2);
//                  break;
//                }
//            }
//        }
//        if (flag == 0){
//          if (flag2 == 0)
//          {
//            flag2 = 1;
//            printf("%d\n", length1);
//          }
//          else
//          {
//            printf("\n%d\n", length1);
//          }
//          }
//    }
//    return 0;
//}
