#include "../exercise.h"
#include <cstring> // 用于 std::memcpy

template<class T>
struct Tensor4D {
    unsigned int shape[4];
    T *data;

    Tensor4D(unsigned int const shape_[4], T const *data_) {
        for (int i = 0; i < 4; ++i) {
            shape[i] = shape_[i];
        }
        unsigned int size = 1;
        for (int i = 0; i < 4; ++i) {
            size *= shape[i];
        }
        data = new T[size];
        std::memcpy(data, data_, size * sizeof(T));
    }

    ~Tensor4D() {
        delete[] data;
    }

    // 禁止复制和移动构造函数
    Tensor4D(Tensor4D const &) = delete;
    Tensor4D(Tensor4D &&) noexcept = delete;

    // 实现单向广播的加法
    Tensor4D &operator+=(Tensor4D const &others) {
        // 计算每个维度的步长
        unsigned int stride[4] = {1, shape[1], shape[1] * shape[2], shape[1] * shape[2] * shape[3]};
        unsigned int other_stride[4] = {1, others.shape[1], others.shape[1] * others.shape[2], others.shape[1] * others.shape[2] * others.shape[3]};

        for (unsigned int i = 0; i < total_size(); ++i) {
            unsigned int index = i;
            unsigned int other_index = 0;
            for (int dim = 0; dim < 4; ++dim) {
                unsigned int idx = index / stride[dim];
                if (others.shape[dim] == 1) {
                    other_index += idx * other_stride[dim];
                } else {
                    other_index += (idx % others.shape[dim]) * other_stride[dim];
                }
                index %= stride[dim];
            }
            data[i] += others.data[other_index];
        }
        return *this;
    }

    // 辅助函数，用于获取张量的总大小
    unsigned int total_size() const {
        unsigned int totalSize = 1;
        for (int i = 0; i < 4; ++i) {
            totalSize *= shape[i];
        }
        return totalSize;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    {
        unsigned int shape[]{1, 2, 3, 4};
        // clang-format off
        int data[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        auto t0 = Tensor4D(shape, data);
        auto t1 = Tensor4D(shape, data);
        t0 += t1;
        for (auto i = 0u; i < sizeof(data) / sizeof(*data); ++i) {
            ASSERT(t0.data[i] == data[i] * 2, "Tensor doubled by plus its self.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        float d0[]{
            1, 1, 1, 1,
            2, 2, 2, 2,
            3, 3, 3, 3,

            4, 4, 4, 4,
            5, 5, 5, 5,
            6, 6, 6, 6};
        // clang-format on
        unsigned int s1[]{1, 2, 3, 1};
        // clang-format off
        float d1[]{
            6,
            5,
            4,

            3,
            2,
            1};
        // clang-format on

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        double d0[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        unsigned int s1[]{1, 1, 1, 1};
        double d1[]{1};

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        
    }
}