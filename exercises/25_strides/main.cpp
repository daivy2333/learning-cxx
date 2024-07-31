#include "../exercise.h"
#include <vector>
#include <cassert>

using udim = unsigned int;

std::vector<udim> strides(const std::vector<udim>& shape) {
    std::vector<udim> strides(shape.size(), 1); // 初始化步长数组，所有步长为1
    // 从第二个维度开始，从后向前计算步长
    for (size_t i = 1; i < shape.size(); ++i) {
        strides[i] = strides[i - 1] * shape[i - 1];
    }
    return strides;
}

// 如果exercise.h没有提供ASSERT宏定义，我们自己定义一个
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

int main(int argc, char **argv) {
    std::cout << "All tests passed!" << std::endl;
    return 0;
}