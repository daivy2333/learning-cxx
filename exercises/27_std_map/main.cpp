#include "../exercise.h"
#include <map>
#include <cassert>

// 如果exercise.h没有提供ASSERT宏定义，我们自己定义一个
#ifndef ASSERT
#define ASSERT(condition, message) assert((condition) && (message))
#endif

template<class k, class v>
bool key_exists(std::map<k, v> const &map, k const &key) {
    return map.find(key) != map.end();
}

template<class k, class v>
void set(std::map<k, v> &map, k key, v value) {
    map[key] = value;  // 这会插入新元素或更新已存在的元素
}

int main(int argc, char **argv) {
    using namespace std::string_literals;

    std::map<std::string, std::string> secrets;

    set(secrets, "hello"s, "world"s);
    ASSERT(key_exists(secrets, "hello"s), "\"hello\" should be in `secrets`");
    ASSERT(!key_exists(secrets, "foo"s), "\"foo\" should not be in `secrets`");

    set(secrets, "foo"s, "bar"s);
    set(secrets, "Infini"s, "Tensor"s);
    ASSERT(secrets["hello"] == "world", "hello -> world");
    ASSERT(secrets["foo"] == "bar", "foo -> bar");
    ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

    set(secrets, "hello"s, "developer"s);
    ASSERT(secrets["hello"] == "developer", "hello -> developer");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
