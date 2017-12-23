#include <iostream>
using namespace std;

int main()
{
    int sum, sum2, sum3;
    int flag;
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 10; j++)
            for (int k = 1; k < 10; k++)
            {
                flag = 0;
                sum = i * 100 + j * 10 + k;
                sum2 = sum * 2;
                sum3 = sum * 3;
                int a[9];
                a[0] = i;
                a[1] = j;
                a[2] = k;
                a[3] = sum2 % 10;
                a[4] = (sum2 / 10) % 10;
                a[5] = (sum2 / 100) % 10;
                a[6] = sum3 % 10;
                a[7] = (sum3 / 10) % 10;
                a[8] = (sum3 / 100) % 10;
                for (int m = 0; m < 9; m++)
                {
                    if (a[m] == 0)
                        flag = 1;
                }
                for (int m = 0; m < 9; m++)
                    for (int n = m + 1; n < 9; n++)
                    {
                        if (a[m] == a[n])
                            flag = 1;
                    }
                if (flag == 0)
                {
                    cout << sum << ' ' << sum2 << ' ' << sum3 << ' ' << endl;
                }
            }
    return 0;
}
