#include "../exercise.h"
#include <cstring>
#include <vector>
#include <cassert> // 断言需要 <cassert>

// 如果exercise.h没有提供ASSERT宏定义，我们自己定义一个
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "The size of the vector should be 5.");
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "The content of the vector should match ans.");
    }
    
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "The size of the vector should be 5.");
        double ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "The content of the vector should match ans.");

        vec.push_back(6);
        ASSERT(vec.size() == 6, "The size of the vector should be 6 after push_back.");
        vec.pop_back();
        ASSERT(vec.size() == 5, "The size of the vector should be 5 after pop_back.");

        vec[4] = 6;
        ASSERT(vec[0] == 1, "The first element should be 1.");
        ASSERT(vec[1] == 2, "The second element should be 2.");
        ASSERT(vec[2] == 3, "The third element should be 3.");
        ASSERT(vec[3] == 4, "The fourth element should be 4.");
        ASSERT(vec[4] == 6, "The fifth element should be 6.");

        vec.insert(vec.begin(), 1.5);
        vec.erase(vec.begin() + 1);

        vec.shrink_to_fit();
        // 这里不进行断言，因为shrink_to_fit不保证改变capacity

        vec.clear();
        ASSERT(vec.empty(), "`vec` is empty now.");
        ASSERT(vec.size() == 0, "The size of the vector should be 0 after clear.");
        // 这里不进行断言，因为clear不改变capacity，除非内存重新分配
    }
    {
        std::vector<char> vec(48, 'z');
        ASSERT(vec[0] == 'z', "The first element should be 'z'.");
        ASSERT(vec[47] == 'z', "The forty-eighth element should be 'z'.");
        ASSERT(vec.size() == 48, "The size of the vector should be 48.");

        vec.resize(16);
        ASSERT(vec.size() == 16, "The size of the vector should be 16 after resize.");

        vec.reserve(256);
        ASSERT(vec.capacity() >= 256, "The capacity of the vector should be at least 256 after reserve.");

        vec.push_back('a');
        vec.push_back('b');
        vec.push_back('c');
        vec.push_back('d');
        ASSERT(vec.size() == 20, "The size of the vector should be 20 after push_back four elements.");
        ASSERT(vec[15] == 'z', "The fifteenth element should still be 'z'.");
        ASSERT(vec[16] == 'a', "The sixteenth element should be 'a'.");
        ASSERT(vec[17] == 'b', "The seventeenth element should be 'b'.");
        ASSERT(vec[18] == 'c', "The eighteenth element should be 'c'.");
        ASSERT(vec[19] == 'd', "The nineteenth element should be 'd'.");
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}