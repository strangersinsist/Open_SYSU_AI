// f1是用int类型存储结果
int f1(unsigned n)
{
    int sum = 1;
    int pow = 1;
    for (unsigned i = 0; i < n; i++)
    {
        pow *= 2;
        sum += pow;
    }
    return sum;
}

// f2是用float类型存储结果
float f2(unsigned n)
{
    float sum = 1;
    float pow = 1;
    for (unsigned i = 0; i < n; i++)
    {
        pow *= 2;
        sum += pow;
    }
    return sum;
}

// 比较f1和f2的运行结果
int main()
{
    for (int i = 0; i < 32; i++)
    {
        printf("%d\t%-20d %.1f\n", i, f1(i), f2(i));
    }
    return 0;
}