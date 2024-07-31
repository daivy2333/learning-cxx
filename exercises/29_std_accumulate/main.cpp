#include "../exercise.h"
#include <numeric>
#include <vector>
#include <cassert>

// 如果exercise.h没有提供ASSERT宏定义，我们自己定义一个
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    
    // 计算张量的总元素数量
    auto total_elements = std::accumulate(shape, shape + std::size(shape), 1, std::multiplies<int>());
    
    // 计算张量占用的字节数
    auto size = sizeof(DataType) * total_elements;
    
    // 断言张量大小是否正确
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}