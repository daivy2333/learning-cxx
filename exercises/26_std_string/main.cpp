#include "../exercise.h"
#include <string>
#include <cassert>

// 如果exercise.h没有提供ASSERT宏定义，我们自己定义一个
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

int main(int argc, char **argv) {
    using namespace std::string_literals;
    auto hello = "Hello"s;
    auto world = "world";
    
    ASSERT((std::is_same_v<decltype(hello), std::string>), "The type of 'hello' should be std::string.");
    // 拼接字符串 "Hello, world!"
    ASSERT((hello + ", " + world + '!' == "Hello, world!"s), "The concatenated string should be \"Hello, world!\".");
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
