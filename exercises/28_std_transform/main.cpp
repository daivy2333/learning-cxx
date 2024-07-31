#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

// 如果exercise.h没有提供ASSERT宏定义，我们自己定义一个
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    std::vector<std::string> ans; // 定义ans以存储转换后的字符串
    ans.resize(val.size()); // 调整ans的大小以匹配val

    // 使用std::transform将val中的每个元素乘以2，然后使用back_inserter将结果转换为字符串存入ans
    std::transform(val.begin(), val.end(), ans.begin(),
                   [](int x) { return std::to_string(x * 2); });

    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}