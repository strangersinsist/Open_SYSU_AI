#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double calculateSampleVariance(const std::vector<double> &data)
{
    // 计算样本均值
    double mean = 0.0;
    for (double value : data)
    {
        mean += value;
    }
    mean /= data.size();
    std::cout << "样本均值: " << mean << std::endl;
    // 计算样本方差
    double variance = 0.0;
    for (double value : data)
    {
        variance += pow(value - mean, 2);
    }
    variance /= (data.size() - 1); // 使用 (n-1) 作为分母，其中 n 是样本大小

    return variance;
}

int main()
{
    // 打开文件
    std::ifstream inputFile("sample_data.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    // 从文件读取数据
    std::vector<double> data;
    double value;

    while (inputFile >> value)
    {
        data.push_back(value);
    }

    // 关闭文件
    inputFile.close();

    // 检查是否成功读取数据
    if (data.empty())
    {
        std::cerr << "文件中没有有效数据" << std::endl;
        return 1;
    }

    // 计算并输出样本方差
    double sampleVariance = calculateSampleVariance(data);
    std::cout << "样本方差: " << sampleVariance << std::endl;

    return 0;
}