#include "../exercise.h"

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
int plus(int a, int b) {
    return a + b;
}

int main(int argc, char **argv) {
    const float tolerance = 1e-5f;
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");
    return 0;
}
