#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//函数声明

int get_size(char *str); //返回该非空字符串的最后一位index
void help();             //显示帮助
void av_to_bv();         //av号转bv
void bv_to_av();         //bv号转av

//全局变量

const string to_bv = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
static bool select_help = true; //  true表示av转bv
long long int tem = 100618342136696320;

//函数实现

int get_size(char *str)
{
    int size = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        size += 1;
    }
    return size - 1;
}

void help()
{
    cout << "Please select your need:" << endl;
    cout << "Press 1 if you want to turn av to bv" << endl;
    cout << "Press 2 if the opposite" << endl;

    int select = 0;

    while (true)
    {
        cin >> select;
        if (select == 1 || select == 2)
        {
            select == 1 ? select_help = true : select_help = false;
            break;
        }
        else
        {
            cout << "Your input seems invalid, try again:" << endl;
            cin.clear();
            cin.sync();
        }
    }
}

void av_to_bv()
{
    //准备av号
    long long int av = 0;
    cout << "Please input your av number:";
    cin >> av;
    char av_2[50];
    for (int i = 0; i < 50; i++)
    {
        av_2[i] = 0;
    }
    _itoa_s(av, av_2, 2);

    //准备中间参数

    const long int mid_num = 177451812;
    char mid_num_2[50];
    for (int i = 0; i < 50; i++)
    {
        mid_num_2[i] = 0;
    }
    _itoa_s(mid_num, mid_num_2, 2);

    //异或运算

    char sec_num_2[50] = {0}; //存储运算结果
    int last_1 = get_size(av_2);
    for (int last = get_size(mid_num_2); last >= 0; last--)
    {
        if (last_1 >= 0)
        {
            sec_num_2[last] = (mid_num_2[last] ^ av_2[last_1]) + '0';
        }
        else
        {
            sec_num_2[last] = mid_num_2[last];
        }
        last_1--;
    }

    //cout << sec_num_2 << endl;测试是否正确

    //转化回十进制

    long long sec_num = 0;
    int t = get_size(sec_num_2);
    for (int i = 0; i <= t; i++)
    {
        sec_num = sec_num * 2 + sec_num_2[i] - '0';
    }

    sec_num += tem; //这里得到最终转化用的输入值

    long long arr[10];
    char bv_tem[10], bv[10];
    for (int i = 0; i < 10; i++)
    {
        bv[i] = bv_tem[i] = 0;
    }

    //进行整除取余操作

    long long power[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; //如果用pow函数可能会出问题
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            power[i] *= 58;
        }
        arr[i] = sec_num / power[i];
        arr[i] = arr[i] % 58;
        bv_tem[i] = to_bv[arr[i]];
    }

    //调整一下顺序（其实可能是随机生成的）

    int random[10] = {6, 2, 4, 8, 5, 9, 3, 7, 1, 0};

    for (int i = 0; i < 10; i++)
    {
        bv[i] = bv_tem[random[i]];
    }

    //最终输出

    cout << "your bv number is:";
    for (int i = 0; i < 10; i++)
    {
        cout << bv[i];
    }
    cout << endl;
}

void bv_to_av()
{
    //准备一下bv号
    char *bv;
    bv = new char[20];
    cout << "please input your bv number:";
    cin >> bv;

    //按照全局序列to_bv转化回相应数字

    long long int *arr;
    int bv_size = strlen(bv);
    arr = new long long int[bv_size];
    for (int i = 0; *(arr + i) != 0; i++) //初始化
    {
        arr[i] = 0;
    }

    for (int i = 0; *(bv + i) != 0; i++)
    {
        for (int j = 0; to_bv[j] != 0; j++)
        {
            if (*(bv + i) == to_bv[j])
            {
                arr[i] = j;
                break;
            }
        }
    }

    /*
    测试一下：
    for (int i = 0; *(arr + i) != 0; i++)
    {
        cout << *(arr + i) << endl;
    }
    */

    //这里做乘方（注意用long long类型）

    int random[10] = {6, 2, 4, 8, 5, 9, 3, 7, 1, 0};

    for (int i = 0; *(arr + i) != 0; i++)
    {
        for (int j = 0; j < random[i]; j++)
        {
            arr[i] *= 58;
        }
    }

    long long int sum = 0;
    for (int i = 0; *(arr + i) != 0; i++)
    {
        sum += arr[i];
    }

    /*
    测试一下：
    cout << sum << endl;
    */

    sum -= tem;

    char sum_2[50];
    for (int i = 0; i < 50; i++)
    {
        sum_2[i] = 0;
    }
    _itoa_s(sum, sum_2, 2);

    const long int mid_num = 177451812;
    char mid_num_2[50];
    for (int i = 0; i < 50; i++)
    {
        mid_num_2[i] = 0;
    }
    _itoa_s(mid_num, mid_num_2, 2);

    //异或运算

    char sec_num_2[50] = {0}; //存储运算结果
    int last_1 = get_size(sum_2);
    for (int last = get_size(mid_num_2); last >= 0; last--)
    {
        if (last_1 >= 0)
        {
            sec_num_2[last] = (mid_num_2[last] ^ sum_2[last_1]) + '0';
        }
        else
        {
            sec_num_2[last] = mid_num_2[last];
        }
        last_1--;
    }

    /*
    测试一下：
    cout << sec_num_2 << endl;
    */

    //转化回十进制

    int av = 0;
    int t = get_size(sec_num_2);
    for (int i = 0; i <= t; i++)
    {
        av = av * 2 + sec_num_2[i] - '0';
    }

    cout << "your av number is:";
    cout << av << endl;
}

int main()
{
    cout << "======================bilibili=========================" << endl;

    help();

    if (select_help)
    {
        av_to_bv();
    }
    else
    {
        bv_to_av();
    }

    system("pause");
    return 0;
}