#include "../exercise.h"

// TODO: ��������������
int add(int a, int b); // ��������

int main(int argc, char **argv) {
    ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

    int x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

int add(int a, int b) {
    // �������������ĺ�
    return a + b; // ��ȫ��������
}
