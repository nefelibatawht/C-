#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max_words 20 // ����ַ�
#define max_num 200  // ���ʵ�������
struct word
{
    char en[max_words];   // Ӣ����ʽ
    char ch[max_words];   //������ʽ
} s[max_num], r[max_num]; //��������
int num;                  //���ʸ���
int rnum;                 //���ǿ���̵ĵ��ʸ���
int n = 1;
int d = 0, c = 0; //cΪ�ش����Ĵ�����dΪ�ش���ȷ�Ĵ���

//ע�����
void printstart()
{
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("----------------------Welcome---------------------\n");
    printf("-------------------��ѡ���Ӧ����------------------\n");
    printf("--------------------------------------------------\n");
    printf("---------       1 .   ���û�ע��       ------------\n");
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
    printf("---------       2 .   �����˺ŵ�¼      -----------\n");
    printf("--------------------------------------------------\n");
    printf("--------------------------------------------------\n");
}
//�û���ע��
void xinyonghuzhuce()
{
    int logtime = 1;                                                         //��¼����
    char usersname[20], password1[16], password2[16], password3[16], mm[16]; //�û�������һ��������룬��һ��ȷ�ϵ����룬��һ��ȷ���������ʱ�ڶ���ȷ�ϵ����룬�����ļ������롣
    FILE *fp;
    fp = fopen("D:\\����ʿ�\\usersdata.txt", "a+");
    if (!fp)
    {
        printf(" error\n");
        exit(1);
    };
    printf("��ע������û���:\n");
    scanf("%s", usersname);
    printf("�뽨������:\n");
    scanf("%s", password1);
    printf("��ȷ������:\n");
    scanf("%s", password2);
    if (strcmp(password1, password2) == 0) //�����һ�������������ȷ�ϵ�����һ����ע��ɹ���
    {
        strcpy(mm, password1);
        printf("ע��ɹ�!,��ӭ���û�");
    }
    else
    {
        printf("���ٴ�ȷ������:\n");
        scanf("%s", password3);
        if (strcmp(password1, password3) == 0) //����һ�β�һ������ڶ���ȷ��һ�¡�
        {
            strcpy(mm, password1);
            printf("��ϲ�㣬ע��ɹ���\n");
        }
        else
        {
            printf("ע��ʧ��!\n");
            getchar();
            getchar(); //��������ȷ�ϲ�һ����ע��ʧ��ֱ���˳���
            exit(1);
        }
    }
    fprintf(fp, "%s %s %d\n", usersname, mm, logtime); //�û��������뻹�г�ʼ��¼�������ļ���
    fclose(fp);
}

//��¼
void login()
{
    char mingzi[40], shuru[40];
    int ch = 0; //�м�����������ж��û����Ƿ���ڡ�
    typedef struct userdata
    {
        char name[20];
        char password[16];
        int logtime;
    } data;
    data userinf[1000]; //����ṹ�����飬�����洢�û���Ϣ
    int i = 0;          //ѭ������
    FILE *fp;
    fp = fopen("D:\\����ʿ�\\usersdata.txt", "a+"); //ֻ�����û������ļ�
    if (!fp)
    {
        printf(" error!\n");
        exit(1);
    }
    printf("�������û���:\n");
    scanf("%s", mingzi); //���û��������Ϣ�洢���ַ�����
    fscanf(fp, "%s%s%d", userinf[i].name, userinf[i].password, &userinf[i].logtime);
    while (!feof(fp)) //����ļ��Ƿ�ȫ����ȡ���
    {
        i++;
        fscanf(fp, "%s%s%d", userinf[i].name, userinf[i].password, &userinf[i].logtime);
    }           //���ļ������е��û���Ϣ����ṹ��
    fclose(fp); //�ر��ļ�
    for (i = 0; i < 1000; i++)
    {
        if (strcmp(mingzi, userinf[i].name) == 0) //�ж��û������ļ����Ƿ�����֮������û���
        {
            ch = 1; //�����ڸ��û�������ch��ֵΪ1��
            printf("���������룺\n");
            scanf("%s", shuru);
            if (strcmp(shuru, userinf[i].password) == 0) //���û�������������û������ļ��е�����ȶ�
            {
                printf("��¼�ɹ������밴�س�������\n");
                userinf[i].logtime++;
                getchar();
                getchar();
            }
            else
            {
                printf("����������������룺\n");
                scanf("%s", shuru);
                if (strcmp(shuru, userinf[i].password) == 0) //�ٴν�������ȶ�
                {
                    printf("��¼�ɹ������밴�س�������\n");
                    userinf[i].logtime++;
                    getchar();
                    getchar();
                }
                else
                {
                    printf("��½ʧ�ܣ�\n");
                    getchar();
                    getchar();
                    exit(1); //��������������ޣ�ͣ�ٺ�ֱ�ӽ�������
                }
            }
        }
    }
    if (ch == 0) //�û������ļ����Ҳ������û��������������û�ע��
    {
        printf("�޴��û�������ע�ᣡ\n");
        getchar();
        getchar();
        exit(1);
    }
}
//����
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
//����
void help()
{
    printf("\n��ϵͳ��Ҫʵ��Ӣ�ﵥ��ѧϰ�Ĺ��ܡ��û��ɶԴʵ��ļ��еĵ��ʽ���Ԥ������ɾ�Ĳ顣");
    printf("\nͬʱ���ɽ�����Ӣ��Ӣ�в��ԡ���ϵͳ���ṩ�˲��Գɼ�����ʾ���ܡ�");
}

//���ļ��ж�ȡ���ʵ���Ϣ
void readfile()
{
    FILE *fp; //����һ���ļ�
    int i = 0;
    fp = fopen("D:\\����ʿ�\\�ʿ�001.txt", "r"); //���ļ�
    if (!fp)                                      //���ļ�������
    {
        printf("\n error�����ļ�ʧ��!");
    }
    while (fscanf(fp, "%s %s ", s[i].en, s[i].ch) == 2) //�ɹ���ȡ����ȡ��һ������
    {
        i++;
    }
    num = i;    //��¼��������
    if (i == 0) //��������Ϊ0
        printf("\n �ļ�Ϊ�գ������ӵ��ʣ�");
    else
        printf("\n");
    fclose(fp); //�ر��ļ�
}
//���ļ���д�뵥�ʵ���Ϣ
void writefile()
{
    FILE *fp; //����һ���ļ�
    int i = 0;
    fp = fopen("D:\\����ʿ�\\�ʿ�001.txt", "w");
    if (!fp) //���ļ�������
    {
        printf("\n���ļ�ʧ��!");
    }
    for (i = 0; i < num; i++) //ѭ����д�뵥��
    {
        -fprintf(fp, "\n%s %s ", s[i].en, s[i].ch);
    }
    printf("\n");
    fclose(fp); //�ر��ļ�
}
//��ȡ���⹮���ļ�
void wreadfile()
{
    FILE *fp; //����һ���ļ�
    int i = 0;
    fp = fopen("D:\\����ʿ�\\reword.txt", "r"); //�򿪴��⹮���ļ�
    if (!fp)                                     //���ļ�Ϊ��
    {
        printf("\n���ļ�ʧ�ܣ�");
    }
    while (fscanf(fp, "%s %s", r[i].en, r[i].ch) == 2) //��ȡ��һ������
    {
        i++;
    }
    rnum = i;   //��¼�����
    if (i == 0) //�������Ϊ0
        printf("\n�㻹û�д��Ŷ��");
    else
        printf("\n");
    fclose(fp); //�ر��ļ�
}
//�ʿ�����
void sort()
{
    int i, j;
    char temp[max_words];
    for (i = 0; i < num - 1; i++) //ѭ������������
    {
        for (j = num - 1; j > i; j--)             //ѭ��������ǰ����֮��ĵ���
            if (strcmp(s[j - 1].en, s[j].en) > 0) /*���ַ���s[j-1].en�����ַ���s[j].en,��ͨ���м�������������ַ���*/
            {
                strcpy(temp, s[j - 1].en); //����Ӣ���ַ���
                strcpy(s[j - 1].en, s[j].en);
                strcpy(s[j].en, temp);
                strcpy(temp, s[j - 1].ch); //���������ַ���
                strcpy(s[j - 1].ch, s[j].ch);
                strcpy(s[j].ch, temp);
            }
    }
}
//��ӵ�����Ϣ
void add()
{
    int i = num, j, into = 1;
    while (into)
    {
        into = 0;
        printf("\n�����뵥�ʵ�Ӣ����ʽ:");
        scanf("%s", s[i].en);                  //������ӵ��ʷ������е���ĩβ
        for (j = 0; j < i; j++)                //ѭ���������е��ʣ��������ӵ����Ƿ��ظ�
            if (strcmp(s[i].en, s[j].en) == 0) //�������ַ������
            {
                printf("���иõ���,������¼��!\n");
                into = 1;
                break;
            }
    }
    printf("\n�����뵥�ʵ�������ʽ:");
    scanf("%s", s[i].ch);
    num++;
    printf("\n���������ϢΪ: Ӣ��: %s ����: %s  ", s[i].en, s[i].ch);
    sort(); //�����ֵ�������
}
//ɾ��������Ϣ
void del()
{
    int i = 0, j = 0;
    char en[max_words]; //Ӣ����ʽ
    printf("\n��������Ҫɾ���ĵ���Ӣ����ʽ:");
    scanf("%s", en);
    for (i = 0; i < num; i++)
        if (strcmp(s[i].en, en) == 0)
        {
            for (j = i; j < num - 1; j++)
                s[j] = s[j + 1];
            num--; //�������� 1
            return;
        }
    printf("\nû���������!");
}
//�޸ĵ�����Ϣ
void modify()
{
    int i = 0, choose = 0, flag = 1; //chooses����ѡ���ʶ��flag�����Ƿ��ҵ�����
    char en[max_words];              //Ӣ����ʽ
    while (flag || choose)
    {
        printf("\n��������Ҫ�޸ĵĵ���Ӣ����ʽ:");
        scanf("%s", en);
        for (i = 0; i < num; i++) //ѭ���������ʣ�������Ҫ�޸ĵ�����ȵ��ַ���
            if (strcmp(s[i].en, en) == 0)
            {
                printf("\n�����뵥����ȷ��Ӣ����ʽ:");
                scanf("%s", s[i].en);
                printf("\n������˵�����ȷ�ĵ�������ʽ:");
                scanf("%s", s[i].ch);
                printf("\n�����޸���ѡ1��������һ����ѡ0:");
                scanf("%d", &choose);
                if (choose == 0)
                    return;
            }
        flag = 0;
    }
    if (!flag)
        printf("\nû���������!");
}
//����Ԥ��
void show()
{
    int i = 0;
    printf("\n���ʣ�     Ӣ��           ����         ");
    sort();
    for (i = 0; i < num; i++)
        printf("\n          %12s    %14s", s[i].en, s[i].ch);
}
//Ӣ�Ĳ�ѯ
void searchen()
{
    int i = 0, choose = 0, flag = 1;
    char en[max_words];
    while (choose || flag) //��������һ����0�ͽ���ѭ��
    {
        printf("\n��������Ҫ��ѯ�ĵ���Ӣ����ʽ:");
        scanf("%s", en);
        for (i = 0; i < num; i++) //���ҵ���Ӣ����ʽ��Ӧ�����
            if (strcmp(s[i].en, en) == 0)
            {
                printf("\n������ʽ��%10s      Ӣ����ʽ��%10s", s[i].ch, s[i].en);
            }
        printf("\n������ѯ��ѡ1��������һ����ѡ0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
        flag = 0;
    }
}
//���Ĳ�ѯ
void searchch()
{
    int i = 0, choose = 0, flag = 1;
    char ch[max_words];
    while (choose || flag)
    {
        printf("\n��������Ҫ��ѯ�ĵ���������ʽ:");
        scanf("%s", ch);
        for (i = 0; i < num; i++) //���ҵ���������ʽ��Ӧ�����
            if (strcmp(s[i].ch, ch) == 0)
            {
                printf("\nӢ����ʽ��%10s       ������ʽ ��%10s", s[i].en, s[i].ch);
            }
        printf("\n������ѯ��ѡ1��������һ����ѡ0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;

        flag = 0;
    }
}

//����Ӣ����
void zytest()
{
    char b1[20];
    int z;
    int choose = 1; //����ѡ��
    int i;
    FILE *fp; //����һ���ļ�
    while (choose)
    {

        i = rand() % num; //���ɽ��ڴʿ���Ŀ֮���������������ȡ�ʿ��еĺ���
        printf("\n��%s��������Ӣ�ĵ���:", s[i].ch);
        scanf("%s", b1);
        fp = fopen("D:\\����ʿ�\\reword.txt", "a+"); //�򿪴���ļ�
        if (!fp)
        {
            printf("\n���ļ��ļ�ʧ�ܣ�");
        }
        for (; strcmp(b1, s[i].en) != 0;)
        {
            fprintf(fp, "%s %s\n", s[i].en, s[i].ch); //�ش����ʱд���ʹ����ļ�
            printf("\n������󣡣�����������:");
            scanf("%s", b1);
            c = c + 1; //����������1
            rnum++;    //���ʹ����ļ��е�������1
        }
        fclose(fp); //�ر��ļ�
        printf("\n��ϲ�㣬�ش���ȷ����10��!\n\n");
        d = d + 1; //���Ե�������1
        printf("������������ѡ1��������һ����ѡ0:��");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//Ӣ���в���
void yztest()
{
    char b1[20];
    int z;
    int choose = 1;
    int i;
    FILE *fp; //����һ���ļ�
    while (choose)
    {
        fp = fopen("D:\\����ʿ�\\reword.txt", "a+"); //���蹮�̵Ĵ���ļ�
        if (!fp)                                      //���ļ�Ϊ��
        {
            printf("\n���ļ�ʧ�ܣ�");
        }
        i = rand() % num; //���ɽ��ڴʿ���Ŀ֮���������������ȡ�ʿ��еĵ���
        printf("\n��%s��������������˼:", s[i].en);
        scanf("%s", b1);
        for (z = 0; strcmp(b1, s[i].ch) != 0; z = z) //�������뺺���뵥������Ӧ���ֲ����
        {
            fprintf(fp, "%s %s\n", s[i].en, s[i].ch); //�ش����ʱд���ʹ����ļ���
            printf("\n������󣡣�����������:");
            scanf("%s", b1);
            c = c + 1; //����������1
            rnum++;    //���ʹ����ļ��е�������1
        }
        fclose(fp); //�ر��ļ�
        printf("\n��ϲ�㣬�ش���ȷ����10��!");
        d = d + 1; //���Ե�������1
        printf("\n\n����������ѡ1��������һ����ѡ0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//��Ӣ��ǿ����
void zyretest()
{
    char b1[20];
    int z;
    int choose = 1;
    int i;
    while (choose)
    {
        i = rand() % rnum; //���ɽ��ڴ���ļ��е�����Ŀ֮���������������ȡ�ʿ��еĺ���
        printf("��%s��������Ӣ�ĵ���:", r[i].ch);
        scanf("%s", b1);
        for (z = 0; strcmp(b1, r[i].en) != 0; z = z) //�������뵥���뺺������Ӧ���ʲ����
        {
            printf("\n������󣡣�����������:");
            scanf("%s", b1);
            c = c + 1; //����������1
        }
        printf("\n��ϲ�㣬�ش���ȷ����10��!\n");
        d = d + 1; //���Ե�������1
        printf("\n����������ѡ1��������һ����ѡ0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//Ӣ�м�ǿ����
void yzretest()
{
    char b1[20];
    int z;
    int choose = 1;
    int i;
    while (choose)
    {
        i = rand() % rnum; //���ɽ��ڴ��⹮���ļ��е�����Ŀ֮���������������ȡ�ʿ��еĵ���
        printf("��%s��������������˼:", r[i].en);
        scanf("%s", b1);
        for (z = 0; strcmp(b1, r[i].ch) != 0; z = z) //�������뺺���뵥������Ӧ���ֲ����
        {
            printf("������󣡣�����������:");
            scanf("%s", b1);
            c = c + 1;
        }
        printf("\n��ϲ�㣬�ش���ȷ����10��!\n\n");
        d = d + 1;
        printf("\n����������ѡ1��������һ����ѡ0:");
        scanf("%d", &choose);
        if (choose == 0)
            return;
    }
}
//�ɼ��б�
void list()
{
    printf("\n �����������:%d�� \n", c);
    printf(" ����������ȷ:%d�� \n", d);
    printf(" ����ܵ÷�Ϊ:%d��\n\n", 10 * d - 10 * c);
}
//�ʵ�ά��
void weihu()
{
    int choose; //ά������ѡ��
    printf("   ------------------\n");
    printf("----   1.���ӵ���\n");
    printf("----   2.�޸ĵ���\n");
    printf("----   3.ɾ������\n");
    printf("----   4.Ӣ�Ĳ�ѯ\n");
    printf("----   5.���Ĳ�ѯ\n");
    printf("----   6.�˳����˵�\n");
    printf("   ------------------\n");
    while (1)
    {
        printf(" \n������ά�����ܱ��:");
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
            printf("\n������1-5");
        }
    }
}
//�û�����
void menudisplay()
{
    printf("\n");
    printf("*********************************************************\n");
    printf("#                                                       #\n");
    printf("#                        ��С��                         #\n");
    printf("#                                                       #\n");
    printf("#       0.�ʿ�          1.����Ԥ��                       #\n");
    printf("#                                                       #\n");
    printf("#       2.���ʱ���(��->Ӣ)    3.���ʱ���(Ӣ->��)          #\n");
    printf("#                                                       #\n");
    printf("#       4.��ѯ�ɼ�          5.��ʹ���(��->Ӣ)           #\n");
    printf("#                                                       #\n");
    printf("#       6.��ʹ���(Ӣ->��)    7.����                     #\n");
    printf("#                                                       #\n");
    printf("#                     8.�˳�                            #\n");
    printf("#                                                       #\n");
    printf("*********************************************************\n");
    printf("\n");
}
void menu()
{

    int item;
    printf("       \n��ѡ������Ҫ�Ĳ���(0-8)���س�ѡ��:");
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
        printf("������0-8\n");
    }
}
int main()
{
    printf("��ӭʹ�ô�С�ױ�������");
    printf("\n");
    loading();
    menudisplay();
    menu();
    printf("\n��Ҫ��ʾ�˵�����������1��ֱ��ѡ��������0��");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        menudisplay();
    case 0:
        menu();
    }
    system("pause"); //����
    return 0;
}
