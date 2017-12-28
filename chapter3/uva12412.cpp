
//长达四小时的奋战，虽然最后还是WA。。。但是和样例至少成功匹配了。
//1. add 中 rank交换一开始没有考虑对，不需要upper lower 两个来夹， 只需要一个最小upper就行。
//2. 最后一个stat 除法时要考虑人数 不是last
//3. 还有在DQ中 不需要用 pattern来确定两种模式， 只需要用或语义就可以了。
//4. 调试能力大大增强 哈哈
//5. \折行不能出现在printf里面的
//6. 可以考虑把class单独成一个类。 编程时候发现C++的类机制很重要，不然各种全局变量用的太不爽了。
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxd 1000
#define EPS 1e-4
#define T
int removed[105];
static int last = 0;
int counts = 0;
struct student
{
    int rank;
    char sid[15];
    int cid;
    char name[15];
    int score[4];
    int total_points;
    double average_points;
} stu[maxd];

void print_menu();
void add();
void DQ(int isq);
void stat();
void init();
int search_sid(char * sid);

int main()
{
#ifdef T
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif // T
    init();
    while(1)
    {
        int choice;
        print_menu();
        scanf("%d", &choice);
        if (choice == 0)
            break;
        if (choice == 1)
            add();
        if (choice == 2)
            DQ(0);
        if (choice == 3)
            DQ(1);
        if (choice == 4)
            printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
        if (choice == 5)
            stat();
    }
    return 0;
}

void print_menu()
{
    printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
    return ;
}

void init()
{
    memset(removed, 0, sizeof(removed));
}
void add()
{
    int pid;
    while (1)
    {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s", stu[last].sid);
        if (strcmp(stu[last].sid, "0") == 0)
                break ;
        pid = search_sid(stu[last].sid);
        scanf("%d", &stu[last].cid);
        scanf("%s", stu[last].name);
        stu[last].total_points = 0;
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &stu[last].score[i]);
            stu[last].total_points += stu[last].score[i];
        }
        stu[last].average_points = (double)stu[last].total_points / 4;
        if (pid == 1)
        {
            stu[last].rank = last;
            int upper = 0;
            int equal = 0;
            if (last == 0)
                stu[last].rank = 1;
            else
            {
                for (int i = 0; i < last; i++)
                {
                    if(stu[last].total_points < stu[i].total_points)
                    {
                        if (stu[i].rank > upper)
                                upper = stu[i].rank;
                    }
                    else if (stu[last].total_points == stu[i].total_points)
                    {
                        equal = 1;
                        stu[last].rank = stu[i].rank;
                        break;
                    }
                }
                for (int i = 0; i < last; i++)
                {
                    if (equal != 1)
                    {
                        stu[last].rank = upper + 1;
                        if (stu[i].rank > upper)
                            stu[i].rank++;
                    }
                    else
                    {
                        if (stu[i].rank > upper)
                            stu[i].rank++;
                    }
                }
            }
            last++;
        }
        if (pid == 0)
        {
            printf("Duplicated SID.\n");
        }
    }
    return ;
}

int search_sid(char * sid)
{
    if (last == 0)
        return 1;
    for (int i = 0; i < last; i++)
    {
        if ((strcmp(stu[i].sid, stu[last].sid) == 0) && removed[i] != 1)
            return 0;
        if ((strcmp(stu[i].sid, stu[last].sid) == 0) && removed[i] == 1)
        {
            removed[i] = 0;
            int upper = 0;
            int equal = 0;
                for (int j = 0; j != i && j < last; j++)
                {
                    if(stu[i].total_points < stu[j].total_points)
                    {
                        if (stu[j].rank > upper)
                                upper = stu[j].rank;
                    }
                    else if (stu[i].total_points == stu[j].total_points)
                    {
                        equal = 1;
                        stu[i].rank = stu[j].rank;
                        break;
                    }
                }
                for (int j = 0; j != i && j < last; j++)
                {
                    if (equal != 1)
                    {
                        stu[i].rank = upper + 1;
                        if (stu[j].rank > upper)
                            stu[j].rank++;
                    }
                    else
                    {
                        if (stu[j].rank > upper)
                            stu[j].rank++;
                    }
                }
                return 2;
        }

    }
    return 1;
}

void DQ(int isq)
{
#ifdef Ts
            for (int i = 0; i < last; i++)
                printf("%d %s %d %s %d %d %d %d %d\n", stu[i].rank, stu[i].sid, stu[i].cid, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]\
                    , stu[i].score[3], stu[i].total_points);
#endif
    while (1)
    {
        int count = 0;
        int pattern = 0;
        char temp[15];
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", temp);
        if (strcmp(temp, "0") == 0)
            break ;
        for (int i = 0; i < last; i++)
        {
            if (removed[i] == 0 && ((strcmp(temp, stu[i].sid)== 0) || ((strcmp(temp, stu[i].name)== 0))))
            {
                if (isq == 1)
                {
                    printf("%d %s %d %s %d %d %d %d %d %.2lf\n", stu[i].rank, stu[i].sid, stu[i].cid, stu[i].name, \
                                stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].total_points, stu[i].average_points + EPS);
                }
                else if (isq == 0)
                {
                    count++;
                    counts++;
                    removed[i] = 1;
                        stu[i].rank = 0;
                    for (int j = 0; j < last; j++)
                    {
                        if (stu[j].total_points > stu[i].total_points)
                                stu[j].rank--;
                    }
                }
            }
        }
        if (isq == 0)
            printf("%d student(s) removed.\n", count);
    }
    return ;
}

void stat()
{
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int cida;
    scanf("%d", &cida);
    double chinese_total = 0;
    int chinese_pass = 0;
    int chinese_fail = 0;
    double math_total = 0;
    int math_pass = 0;
    int math_fail = 0;
    double english_total = 0;
    int english_pass = 0;
    int english_fail = 0;
    double programming_total = 0;
    int programming_pass = 0;
    int programming_fail = 0;
    int pass_all = 0;
    int pass_three = 0;
    int pass_two = 0;
    int pass_one = 0;
    int fail_all = 0;
    int fail_times;
    int count2 = 0;
    for (int i = 0; i < last; i++)
    {
        if (removed[i] != 1)
        {
        if (cida == 0 || stu[i].cid == cida)
        {
            fail_times = 0;
            chinese_total       += stu[i].score[0];
            math_total          += stu[i].score[1];
            english_total       += stu[i].score[2];
            programming_total   += stu[i].score[3];
            if (stu[i].score[0] < 60)
            {
                fail_times++;
                chinese_fail++;
            }
            else
                chinese_pass++;
            if (stu[i].score[1] < 60)
            {
                fail_times++;
                math_fail++;
            }
            else
                math_pass++;
            if (stu[i].score[2] < 60)
            {
                fail_times++;
                english_fail++;
            }
            else
                english_pass++;
            if (stu[i].score[3] < 60)
            {
                fail_times++;
                programming_fail++;
            }
            else
                programming_pass++;
            switch(fail_times)
            {
                case 0:
                    pass_all++;
                    break;
                case 1:
                    pass_three++;
                    break;
                case 2:
                    pass_two++;
                    break;
                case 3:
                    pass_one++;
                    break;
                case 4:
                    fail_all++;
                    break;
            }
        }
        if (stu[i].cid != cida && cida != 0)
            count2++;
        }
    }
        printf("Chinese\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n", chinese_total / (last - counts - count2)  + EPS, chinese_pass, chinese_fail);
        printf("Mathematics\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n", math_total / (last - counts - count2) + EPS, math_pass, math_fail);
        printf("English\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n", english_total / (last - counts - count2) + EPS, english_pass, english_fail);
        printf("Programming\nAverage Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n", programming_total / (last - counts - count2) + EPS, programming_pass, programming_fail);
        printf("Overall:\nNumber of students who passed all subjects: %d\n", pass_all);
        printf("Number of students who passed 3 or more subjects: %d\n", pass_all + pass_three);
        printf("Number of students who passed 2 or more subjects: %d\n", pass_all + pass_three + pass_two);
        printf("Number of students who passed 1 or more subjects: %d\n", pass_all + pass_three + pass_two + pass_one);
        printf("Number of students who failed all subjects: %d\n\n", fail_all);
}
