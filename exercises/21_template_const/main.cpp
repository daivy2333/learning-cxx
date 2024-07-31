#include "../exercise.h"
#include <cstring>
#include <cassert> // 包含断言库

template<unsigned int N, class T>
struct Tensor {
    unsigned int shape[N];
    T *data;

    // 构造函数
    Tensor(unsigned int const (&shape_)[N]) {
        // 复制形状数组
        for (unsigned int i = 0; i < N; ++i) {
            shape[i] = shape_[i];
        }

        // 计算总大小
        unsigned int size = 1;
        for (unsigned int i = 0; i < N; ++i) {
            size *= shape[i];
        }

        // 分配内存并初始化
        data = new T[size];
        std::memset(data, 0, size * sizeof(T));
    }

    // 析构函数
    ~Tensor() {
        delete[] data;
    }

    // 禁止复制和移动
    Tensor(Tensor const &) = delete;
    Tensor(Tensor &&) noexcept = delete;

    // 重载下标操作符
    T &operator[](unsigned int const indices[N]) {
        return data[data_index(indices)];
    }
    T const &operator[](unsigned int const indices[N]) const {
        return data[data_index(indices)];
    }

private:
    // 计算数据索引
    unsigned int data_index(unsigned int const indices[N]) const {
        unsigned int index = 0;
        unsigned int stride = 1; // 步长
        for (int i = N - 1; i >= 0; --i) {
            // 断言确保索引在形状范围内
            assert(indices[i] < shape[i]);
            index += indices[i] * stride;
            stride *= shape[i];
        }
        return index;
    }
};

// 断言宏定义，如果需要
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

// 主函数
int main() {
    {
        unsigned int shape[]{2, 3, 4, 5};
        auto tensor = Tensor<4, int>(shape);

        unsigned int i0[]{0, 0, 0, 0};
        tensor[i0] = 1;
        ASSERT(tensor[i0] == 1, "tensor[i0] should be 1");

        unsigned int i1[]{1, 2, 3, 4};
        tensor[i1] = 2; // 注意这里应该是 i1
        ASSERT(tensor[i1] == 2, "tensor[i1] should be 2");
    }
    {
        unsigned int shape[]{7, 8, 128};
        auto tensor = Tensor<3, float>(shape);

        unsigned int i0[]{0, 0, 0};
        tensor[i0] = 1.f;
        ASSERT(tensor[i0] == 1.f, "tensor[i0] should be 1");

        unsigned int i1[]{3, 4, 99};
        tensor[i1] = 2.f; // 注意这里应该是 i1
        ASSERT(tensor[i1] == 2.f, "tensor[i1] should be 2");
    }
    return 0;
}