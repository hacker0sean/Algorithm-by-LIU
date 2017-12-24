//#include <iostream>
//#include <cstring>
//#include <stdio.h>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//    char s[100];
//    int a[4] = {0};
//    int T;
//    cin >> T;
//    double sum;
//    while (T--)
//    {
//        memset(a, 0, sizeof(a));
//        sum = 0;
//        scanf("%s", s);
//        int length = strlen(s);
//        for (int i = 0; i < length; i++)
//        {
//            int temp = i;
//            int times = 0;
//            if (s[i+1] >= '0' && s[i+1] <= '9')
//            {
//                while (s[i+1] >= '0' && s[i+1] <= '9')
//                {
//                    times = times*10 + s[i+1] - '0';
//                    i++;
//                }
//            }
//            else
//                times = 1;
//            switch (s[temp])
//            {
//                case 'C' :
//                a[0] += times;
//                break;
//
//                case 'H' :
//                a[1] += times;
//                break;
//
//                case 'O' :
//                a[2] += times;
//                break;
//
//                case 'N' :
//                a[3] += times;
//                break;
//
//                default:
//                break;
//            }
//        }
//        sum = a[0] * 12.01 + a[1] * 1.008 + a[2] * 16.00 + a[3] * 14.01;
//        printf("%.3lf\n", sum);
//    }
//    return 0;
//}
