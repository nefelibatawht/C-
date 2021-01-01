#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max_words 20 // 最大字符
#define max_num 200  // 单词的最大个数
struct word
{
    char en[max_words];   // 英文形式
    char ch[max_words];   //中文形式
} s[max_num], r[max_num]; //单词数组
int num;                  //单词个数
int rnum;                 //需加强巩固的单词个数
int n = 1;
int d = 0, c = 0; //c为回答错误的次数，d为回答正确的次数

//注册界面
void printstart()
{
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("----------------------Welcome---------------------\n");
    printf("-------------------请选择对应数字------------------\n");
    printf("--------------------------------------------------\n");
    printf("---------       1 .   新用户注册       ------------\n");
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("---------       2 .   已有账号登录      -----------\n");
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
}
//用户名注册
void xinyonghuzhuce()
{
    int logtime = 1;                                                         //登录次数
    char usersname[20], password1[16], password2[16], password3[16], mm[16]; //用户名，第一次设的密码，第一次确认的密码，第一次确认密码错误时第二次确认的密码，存入文件的密码。
    FILE *fp;
    fp = fopen("D:\\课设词库\\usersdata.txt", "a+");
    if (!fp)
    {
        printf(" error\n");
        exit(1);
    };
    printf("请注册你的用户名:\n");
    scanf("%s", usersname);
    printf("请建立密码:\n");
    scanf("%s", password1);
    printf("请确认密码:\n");
    scanf("%s", password2);
    if (strcmp(password1, password2) == 0) //如果第一次输入的密码与确认的密码一致则注册成功。
    {
        strcpy(mm, password1);
        printf("注册成功!,欢迎新用户");
    }
    else
    {
        printf("请再次确认密码:\n");
        scanf("%s", password3);
        if (strcmp(password1, password3) == 0) //若第一次不一致则需第二次确认一致。
        {
            strcpy(mm, password1);
            printf("恭喜你，注册成功！\n");
        }
        else
        {
            printf("注册失败!\n");
            getchar();
            getchar(); //密码两次确认不一致则注册失败直接退出。
            exit(1);
        }
    }
    fprintf(fp, "%s %s %d\n", usersname, mm, logtime); //用户名与密码还有初始登录数存入文件。
    fclose(fp);
}

//登录
void login()
{
    char mingzi[40], shuru[40];
    int ch = 0; //中间变量，用来判断用户名是否存在。
    typedef struct userdata
    {
        char name[20];
        char password[16];
        int logtime;
    } data;
    data userinf[1000]; //定义结构体数组，用来存储用户信息
    int i = 0;          //循环变量
    FILE *fp;
    fp = fopen("D:\\课设词库\\usersdata.txt", "a+"); //只读打开用户数据文件
    if (!fp)
    {
        printf(" error!\n");
        exit(1);
    }
    printf("请输入用户名:\n");
    scanf("%s", mingzi); //将用户输入的信息存储到字符数组
    fscanf(fp, "%s%s%d", userinf[i].name, userinf[i].password, &userinf[i].logtime);
    while (!feof(fp)) //检测文件是否全部读取完毕
    {
        i++;
        fscanf(fp, "%s%s%d", userinf[i].name, userinf[i].password, &userinf[i].logtime);
    }           //将文件里所有的用户信息读入结构体
    fclose(fp); //关闭文件
    for (i = 0; i < 1000; i++)
    {
        if (strcmp(mingzi, userinf[i].name) == 0) //判断用户数据文件里是否有与之相配的用户名
        {
            ch = 1; //若存在该用户名，则将ch赋值为1；
            printf("请输入密码：\n");
            scanf("%s", shuru);
            if (strcmp(shuru, userinf[i].password) == 0) //将用户输入的密码与用户数据文件中的密码比对
            {
                printf("登录成功！（请按回车继续）\n");
                userinf[i].logtime++;
                getchar();
                getchar();
            }
            else
            {
                printf("密码错误，请重新输入：\n");
                scanf("%s", shuru);
                if (strcmp(shuru, userinf[i].password) == 0) //再次进行密码比对
                {
                    printf("登录成功！（请按回车继续）\n");
                    userinf[i].logtime++;
                    getchar();
                    getchar();
                }
                else
                {
                    printf("登陆失败！\n");
                    getchar();
                    getchar();
                    exit(1); //密码输入次数超限，停顿后直接结束程序。
                }
            }
        }
    }
    if (ch == 0) //用户数据文件里找不到该用户名，引导进行用户注册
    {
        printf("无此用户名，请注册！\n");
        getchar();
        getchar();
        exit(1);
    }
}
//加载
void loading()
{
    int n;
    printstart();
    scanf("%d", &n);
    system("cls");
    switch (n)
    {
    case 1:
        xinyonghuzhuce();
        break;
    case 2:
        login();
        system("cls");
        break;
    }
}
//帮助
void help()
{
    printf("\n本系统主要实现英语单词学习的功能。用户可对词典文件中的单词进行预览，增删改查。");
    printf("\n同时还可进行中英、英中测试。本系统还提供了测试成绩的显示功能。");
}

//从文件中读取单词的信息
void readfile()
{
    FILE *fp; //声明一个文件
    int i = 0;
    fp = fopen("D:\\课设词库\\词库001.txt", "r"); //打开文件
    if (!fp)                                      //若文件不存在
    {
        printf("\n error！打开文件失败!");
    }
    while (fscanf(fp, "%s %s ", s[i].en, s[i].ch) == 2) //成功读取并读取下一个单词
    {
        i++;
    }
    num = i;    //记录单词总数
    if (i == 0) //若单词数为0
        printf("\n 文件为空，请增加单词！");
    else
        printf("\n");
    fclose(fp); //关闭文件
}
//向文件中写入单词的信息
void writefile()
{
    FILE *fp; //声明一个文件
    int i = 0;
    fp = fopen("D:\\课设词库\\词库001.txt", "w");
    if (!fp) //若文件不存在
    {
        printf("\n打开文件失败!");
    }
    for (i = 0; i < num; i++) //循环以写入单词
    {
        -fprintf(fp, "\n%s %s ", s[i].en, s[i].ch);
    }
    printf("\n");
    fclose(fp); //关闭文件
}
//读取错题巩固文件
void wreadfile()
{
    FILE *fp; //声明一个文件
    int i = 0;
    fp = fopen("D:\\课设词库\\reword.txt", "r"); //打开错题巩固文件
    if (!fp)                                     //若文件为空
    {
        printf("\n打开文件失败！");
    }
    while (fscanf(fp, "%s %s", r[i].en, r[i].ch) == 2) //读取下一个单词
    {
        i++;
    }
    rnum = i;   //记录错词数
    if (i == 0) //若错次数为0
        printf("\n你还没有错词哦！");
    else
        printf("\n");
    fclose(fp); //关闭文件
}
//词库排序
void sort()
{
    int i, j;
    char temp[max_words];
    for (i = 0; i < num - 1; i++) //循环遍历单词数
    {
        for (j = num - 1; j > i; j--)             //循环遍历当前单词之后的单词
            if (strcmp(s[j - 1].en, s[j].en) > 0) /*若字符串s[j-1].en大于字符串s[j].en,则通过中间变量调换两个字符串*/
            {
                strcpy(temp, s[j - 1].en); //调换英文字符串
                strcpy(s[j - 1].en, s[j].en);
                strcpy(s[j].en, temp);
                strcpy(temp, s[j - 1].ch); //调换中文字符串
                strcpy(s[j - 1].ch, s[j].ch);
                strcpy(s[j].ch, temp);
            }
    }
}
//添加单词信息
void add()
{
    int i = num, j, into = 1;
    while (into)
    {
        into = 0;
        printf("\n请输入单词的英文形式:");
        scanf("%s", s[i].en);                  //将所添加单词放在已有单词末尾
        for (j = 0; j < i; j++)                //循环遍历已有单词，检查所添加单词是否重复
            if (strcmp(s[i].en, s[j].en) == 0) //若两个字符串相等
            {
                printf("已有该单词,请重新录入!\n");
                into = 1;
                break;
            }
    }
    printf("\n请输入单词的中文形式:");
    scanf("%s", s[i].ch);
    num++;
    printf("\n您输入的信息为: 英文: %s 中文: %s  ", s[i].en, s[i].ch);
    sort(); //调用字典排序函数
}
//删除单词信息
void del()
{
    int i = 0, j = 0;
    char en[max_words]; //英文形式
    printf("\n请输入你要删除的单词英文形式:");
    scanf("%s", en);
    for (i = 0; i < num; i++)
        if (strcmp(s[i].en, en) == 0)
        {
            for (j = i; j < num - 1; j++)
                s[j] = s[j + 1];
            num--; //数量减少 1
            return;
        }
    printf("\n没有这个单词!");
}
//修改单词信息
void modify()
{
    int i = 0, choose = 0, flag = 1; //chooses代表选项标识，flag代表是否找到单词
    char en[max_words];              //英文形式
    while (flag || choose)
    {
        printf("\n请输入你要修改的单词英文形式:");
        scanf("%s", en);
        for (i = 0; i < num; i++) //循环遍历单词，找与所要修改单词相等的字符串
            if (strcmp(s[i].en, en) == 0)
            {
                printf("\n请输入单词正确的英文形式:");
                scanf("%s", s[i].en);
                printf("\n请输入此单词正确的的中文形式:");
                scanf("%s", s[i].ch);
                printf("\n继续修改请选1，返回上一级请选0:");
                scanf("%d", &choose);
                if (choose == 0)
                    return;
            }
        flag = 0;
    }
    if (!flag)
        printf("\n没有这个单词!");
}
//单词预览
void show()
{
    int i = 0;
    printf("\n单词：     英文           中文         ");
    sort();
    for (i = 0; i < num; i++)
        printf("\n          %12s    %14s", s[i].en, s[i].ch);
}
//英文查询
void searchen()
{
    int i = 0, choose = 0, flag = 1;
    char en[max_words];
    while (choose || flag) //当其中有一个非0就进入循环
    {
        printf("\n请输入你要查询的单词英文形式:");
        scanf("%s", en);
        for (i = 0; i < num; i++) //先找到该英文形式对应的序号
            if (strcmp(s[i].en, en) == 0)
            {
                printf("\n中文形式：%10s      英文形式：%10s", s[i].ch, s[i].en);
            }
        printf("\n继续查询请选1，返回上一级请选0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
        flag = 0;
    }
}
//中文查询
void searchch()
{
    int i = 0, choose = 0, flag = 1;
    char ch[max_words];
    while (choose || flag)
    {
        printf("\n请输入你要查询的单词中文形式:");
        scanf("%s", ch);
        for (i = 0; i < num; i++) //先找到该中文形式对应的序号
            if (strcmp(s[i].ch, ch) == 0)
            {
                printf("\n英文形式：%10s       中文形式 ：%10s", s[i].en, s[i].ch);
            }
        printf("\n继续查询请选1，返回上一级请选0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;

        flag = 0;
    }
}

//中译英测试
void zytest()
{
    char b1[20];
    int z;
    int choose = 1; //回退选择
    int i;
    FILE *fp; //声明一个文件
    while (choose)
    {

        i = rand() % num; //生成介于词库数目之间的随机数，随机抽取词库中的汉字
        printf("\n【%s】请输入英文单词:", s[i].ch);
        scanf("%s", b1);
        fp = fopen("D:\\课设词库\\reword.txt", "a+"); //打开错词文件
        if (!fp)
        {
            printf("\n打开文件文件失败！");
        }
        for (; strcmp(b1, s[i].en) != 0;)
        {
            fprintf(fp, "%s %s\n", s[i].en, s[i].ch); //回答错误时写入错词巩固文件
            printf("\n输入错误！！请重新输入:");
            scanf("%s", b1);
            c = c + 1; //做错单词数加1
            rnum++;    //单词巩固文件中单词数加1
        }
        fclose(fp); //关闭文件
        printf("\n恭喜你，回答正确，加10分!\n\n");
        d = d + 1; //做对单词数加1
        printf("（继续测试请选1，返回上一级请选0:）");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//英译中测试
void yztest()
{
    char b1[20];
    int z;
    int choose = 1;
    int i;
    FILE *fp; //声明一个文件
    while (choose)
    {
        fp = fopen("D:\\课设词库\\reword.txt", "a+"); //打开需巩固的错词文件
        if (!fp)                                      //若文件为空
        {
            printf("\n打开文件失败！");
        }
        i = rand() % num; //生成介于词库数目之间的随机数，随机抽取词库中的单词
        printf("\n【%s】请输入中文意思:", s[i].en);
        scanf("%s", b1);
        for (z = 0; strcmp(b1, s[i].ch) != 0; z = z) //若所输入汉字与单词所对应汉字不相等
        {
            fprintf(fp, "%s %s\n", s[i].en, s[i].ch); //回答错误时写入错词巩固文件中
            printf("\n输入错误！！请重新输入:");
            scanf("%s", b1);
            c = c + 1; //做错单词数加1
            rnum++;    //单词巩固文件中单词数加1
        }
        fclose(fp); //关闭文件
        printf("\n恭喜你，回答正确，加10分!");
        d = d + 1; //做对单词数加1
        printf("\n\n继续测试请选1，返回上一级请选0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//中英加强记忆
void zyretest()
{
    char b1[20];
    int z;
    int choose = 1;
    int i;
    while (choose)
    {
        i = rand() % rnum; //生成介于错词文件中单词数目之间的随机数，随机抽取词库中的汉字
        printf("【%s】请输入英文单词:", r[i].ch);
        scanf("%s", b1);
        for (z = 0; strcmp(b1, r[i].en) != 0; z = z) //若所输入单词与汉字所对应单词不相等
        {
            printf("\n输入错误！！请重新输入:");
            scanf("%s", b1);
            c = c + 1; //做错单词数加1
        }
        printf("\n恭喜你，回答正确，加10分!\n");
        d = d + 1; //做对单词数加1
        printf("\n继续测试请选1，返回上一级请选0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//英中加强记忆
void yzretest()
{
    char b1[20];
    int z;
    int choose = 1;
    int i;
    while (choose)
    {
        i = rand() % rnum; //生成介于错题巩固文件中单词数目之间的随机数，随机抽取词库中的单词
        printf("【%s】请输入中文意思:", r[i].en);
        scanf("%s", b1);
        for (z = 0; strcmp(b1, r[i].ch) != 0; z = z) //若所输入汉字与单词所对应汉字不相等
        {
            printf("输入错误！！请重新输入:");
            scanf("%s", b1);
            c = c + 1;
        }
        printf("\n恭喜你，回答正确，加10分!\n\n");
        d = d + 1;
        printf("\n继续测试请选1，返回上一级请选0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//成绩列表
void list()
{
    printf("\n 共计输入错误:%d次 \n", c);
    printf(" 共计输入正确:%d次 \n", d);
    printf(" 你的总得分为:%d分\n\n", 10 * d - 10 * c);
}
//词典维护
void weihu()
{
    int choose; //维护功能选择
    printf("   ------------------\n");
    printf("----   1.增加单词\n");
    printf("----   2.修改单词\n");
    printf("----   3.删除单词\n");
    printf("----   4.英文查询\n");
    printf("----   5.中文查询\n");
    printf("----   6.退出本菜单\n");
    printf("   ------------------\n");
    while (1)
    {
        printf(" \n请输入维护功能编号:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            add();
            writefile();
            break;
        case 2:
            modify();
            writefile();
            break;
        case 3:
            del();
            writefile();
            break;
        case 4:
            searchen();
            break;
        case 5:
            searchch();
            break;
        case 6:
            return;
        default:
            printf("\n请输入1-5");
        }
    }
}
//用户界面
void menudisplay()
{
    printf("\n");
    printf("*********************************************************\n");
    printf("#                                                       #\n");
    printf("#                        词小易                         #\n");
    printf("#                                                       #\n");
    printf("#       0.词库          1.单词预览                       #\n");
    printf("#                                                       #\n");
    printf("#       2.单词背诵(中->英)    3.单词背诵(英->中)          #\n");
    printf("#                                                       #\n");
    printf("#       4.查询成绩          5.错词巩固(中->英)           #\n");
    printf("#                                                       #\n");
    printf("#       6.错词巩固(英->中)    7.帮助                     #\n");
    printf("#                                                       #\n");
    printf("#                     8.退出                            #\n");
    printf("#                                                       #\n");
    printf("*********************************************************\n");
    printf("\n");
}
void menu()
{

    int item;
    printf("       \n请选择您需要的操作(0-8)按回车选择:");
    scanf("%d", &item);
    printf("\n");
    readfile();
    switch (item)
    {
    case 0:
        weihu();
        break;
    case 1:
        show();
        break;
    case 2:
        writefile();
        zytest();
        break;
    case 3:
        yztest();
        break;
    case 4:
        list();
        break;
    case 5:
        wreadfile();
        zyretest();
        break;
    case 6:
        wreadfile();
        yzretest();
        break;
    case 7:
        help();
        break;
    case 8:

        break;
    default:
        printf("请输入0-8\n");
    }
}
int main()
{
    printf("欢迎使用词小易背记助手");
    printf("\n");
    loading();
    menudisplay();
    menu();
    printf("\n需要显示菜单界面请输入1，直接选择请输入0：");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        menudisplay();
    case 0:
        menu();
    }
    system("pause"); //缓冲
    return 0;
}
