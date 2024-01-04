#include <iostream>
#include <cmath>
#include <bitset>

// 检查数字是否为负数
bool isNegative(int num) {
    return (num < 0);
}

// 反转一个数字的二进制位
int reverseBits(int num) {
    int result = 0;
    while (num > 0) {
        result <<= 1;  // 左移结果
        result |= (num & 1);  // 将结果的最右边位设置为数字的最右边位
        num >>= 1;  // 右移数字
    }
    return result;
}

// 处理整数输入
void processInteger(int num) {
    if (std::abs(num) < 32768) {
        // 将32位整数切割成7位段并为每个段添加标记，表示是否为最后一个段
        std::bitset<32> binaryRepresentation(reverseBits(std::abs(num)));  // 反转位
        for (int i = 0; i < 32; i += 8) {
            std::bitset<8> segment(binaryRepresentation.to_string().substr(i, 8));
            if (segment.to_ulong() != 0 || i == 24) {
                // 输出非零段或最后一个段
                std::cout << segment << " ";
            }
        }
        std::cout << std::endl;
    } else {
        // 对于大于或等于32768的数字，使用二进制补码表示
        std::bitset<32> binaryRepresentation(num);
        std::cout << binaryRepresentation << std::endl;
    }
}
// 处理小数输入
void processDecimal(double num) {
    int integerPart = static_cast<int>(num);
    double decimalPart = num - integerPart;
    // 处理整数部分
    processInteger(integerPart);
    // 处理小数部分
    if (decimalPart != 0) {
        std::string decimalString = std::to_string(decimalPart).substr(2);  // 移除"0."并反转剩余部分
        std::reverse(decimalString.begin(), decimalString.end());
        std::cout << decimalString << std::endl;
    }
}

int main() {
    std::cout << "输入一个数字：";
    double input;
    std::cin >> input;

    if (std::floor(input) == input) {
        // 输入是整数
        processInteger(static_cast<int>(input));
    } else {
        // 输入是小数
        processDecimal(input);
    }

    return 0;
}
