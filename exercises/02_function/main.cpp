#include "../exercise.h"

// TODO: 在这里声明函数
int add(int a, int b); // 函数声明

int main(int argc, char **argv) {
    ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

    int x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

int add(int a, int b) {
    // 返回两个参数的和
    return a + b; // 补全函数定义
}
