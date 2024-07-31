#include "../exercise.h"

struct Fibonacci {
    int numbers[11]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    // TODO: 修改方法签名和实现，使测试通过
    int get(int i) {
        return numbers[i];
    }
}FIB;

int main(int argc, char **argv) {
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
