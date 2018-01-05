//主要就是top， bottom数组谁先走完（以某一数组为基数组），走完退出循环，分成了四类（有两类被合并了），最后得出结果。
//此题有一个大坑，就是以两个都可以作为基数组， 让另一个数组在这一基数组上面跑， 一开始我只考虑了 top 在 bottom上面跑 结果怎么也做不对。。。
#include <stdio.h>
#include <string.h>
#define test
char top[1050];
char bottom[1050];
const int max = 3;
int testa (char* top, char* bottom){
    int i = 0, j = 0;
    int count = 0;
    int flag = 0;
    int length = strlen(top);
    while (bottom[i] != '\0'){
        int temp_i = i;
        int temp_j = j;
        while ((top[j] != '\0') && (bottom[i] != '\0') && ((top[j] - '0' + bottom[i] - '0')  <= 3)) {i++; j++;}
        if (top[j] != '\0' && bottom[i] != '\0') {
            i = temp_i + 1;
            j = temp_j;
            count++;
        }
        else if (top[j] != '\0' && bottom[i] == '\0'){
            count = strlen(bottom);
            break;
        }
        else {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        count = strlen(bottom);
    else{
        do{
            count++;
        }while(top[j++] != '\0');
        count--;
    }
    return count;
}

int main() {
#ifdef testc
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    memset(top, 0, sizeof(top));
    memset(bottom, 0, sizeof(bottom));
    while ((scanf("%s%s",bottom, top) == 2)){
        int count1 = testa (top, bottom);
        int count2 = testa (bottom, top);
        int count = (count1 > count2) ? count2 : count1;
        printf("%d\n", count);
        memset(top, 0, sizeof(top));
        memset(bottom, 0, sizeof(bottom));
    }
}
