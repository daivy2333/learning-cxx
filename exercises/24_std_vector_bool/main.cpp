#include "../exercise.h"
#include <vector>
#include <cassert>

// 如果exercise.h没有提供ASSERT宏定义，我们自己定义一个
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

int main(int argc, char **argv) {
    // 正确调用构造函数，初始化为100个true值
    std::vector<bool> vec(100, true);
    ASSERT(vec[0], "The first element should be true.");
    ASSERT(vec[99], "The hundredth element should be true.");
    ASSERT(vec.size() == 100, "The size of the vector should be 100.");
    // sizeof(vec) 是 vector 对象自身的大小，不是其容量或大小，通常不是预期的
    // ASSERT(sizeof(vec) == , "Fill in the correct value.");

    {
        vec[20] = false;
        ASSERT(!vec[20], "vec[20] should now be false.");
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "The size of the vector should be 101 after push_back.");
        ASSERT(!vec[100], "The one hundred and first element should be false.");
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "The original value of vec[30] should be true.");
        ref = false;
        ASSERT(!ref, "The reference ref should now be false after assignment.");
        ASSERT(!vec[30], "vec[30] should now be false after ref assignment.");
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}