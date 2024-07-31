#include "../exercise.h"

#include "../exercise.h"

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    DynFibonacci(int capacity): cached(2) {
        cache = new size_t[capacity];
        cache[0] = 0;
        cache[1] = 1;
    }

    // 复制构造器
    DynFibonacci(const DynFibonacci &other): cached(other.cached) {
        cache = new size_t[other.cached + 1]; // 复制时需要包含其他对象的缓存大小
        for (int i = 0; i <= other.cached; ++i) {
            cache[i] = other.cache[i];
        }
    }

    // 析构器
    ~DynFibonacci() {
        delete[] cache;
    }

    // 斐波那契计算
    size_t get(int i) {
        if (i < 0) return 0; // 负数输入的处理
        if (i < cached) return cache[i]; // 缓存中已有的值直接返回
        for (; cached <= i; ++cached) { // 计算到i为止
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }

    // const版本的get方法
    size_t get(int i) const {
        if (i < 0) return 0; // 负数输入的处理
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
    }
};

// main函数和ASSERT宏定义需要根据exercise.h文件来实现

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = fib;
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}
