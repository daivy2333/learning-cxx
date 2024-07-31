#include "../exercise.h"

// READ: 虚函数 <https://zh.cppreference.com/w/cpp/language/virtual>

struct A {
    virtual char virtual_name() const {
        return 'A';
    }
    char direct_name() const {
        return 'A';
    }
};
struct B : public A {
    // READ: override <https://zh.cppreference.com/w/cpp/language/override>
    char virtual_name() const override {
        return 'B';
    }
    char direct_name() const {
        return 'B';
    }
};
struct C : public B {
    // READ: final <https://zh.cppreference.com/w/cpp/language/final>
    char virtual_name() const final {
        return 'C';
    }
    char direct_name() const {
        return 'C';
    }
};
struct D : public C {
    char direct_name() const {
        return 'D';
    }
};

int main(int argc, char **argv) {
    constexpr auto MSG = "Replace '?' with its correct name.";

    A a;
    B b;
    C c;
    D d;

    
    ASSERT(a.virtual_name() == 'A', MSG); // A::virtual_name called
    ASSERT(b.virtual_name() == 'B', MSG); // B::virtual_name called
    ASSERT(c.virtual_name() == 'C', MSG); // C::virtual_name called, marked final
    ASSERT(d.virtual_name() == 'C', MSG); // D cannot override, C::virtual_name called

    ASSERT(a.direct_name() == 'A', MSG); // A::direct_name called
    ASSERT(b.direct_name() == 'B', MSG); // B::direct_name called
    ASSERT(c.direct_name() == 'C', MSG); // C::direct_name called
    ASSERT(d.direct_name() == 'D', MSG); // D::direct_name called, hiding C::direct_name

    A &rab = b;
    B &rbc = c;
    C &rcd = d;

    ASSERT(rab.virtual_name() == 'B', MSG); // B::virtual_name called, through A reference
    ASSERT(rbc.virtual_name() == 'C', MSG); // C::virtual_name called, through B reference
    ASSERT(rcd.virtual_name() == 'C', MSG); // C::virtual_name called, through C reference

    ASSERT(rab.direct_name() == 'A', MSG); // A::direct_name called, through A reference
    ASSERT(rbc.direct_name() == 'B', MSG); // B::direct_name called, through B reference
    ASSERT(rcd.direct_name() == 'C', MSG); // C::direct_name called, through C reference

    A &rac = c;
    B &rbd = d;

    ASSERT(rac.virtual_name() == 'C', MSG); // C::virtual_name called, through A reference
    ASSERT(rbd.virtual_name() == 'C', MSG); // C::virtual_name called, through B reference

    ASSERT(rac.direct_name() == 'A', MSG); // A::direct_name called, through A reference
    ASSERT(rbd.direct_name() == 'B', MSG); // B::direct_name called, through B reference

    A &rad = d;

    ASSERT(rad.virtual_name() == 'C', MSG); // C::virtual_name called, through A reference
    ASSERT(rad.direct_name() == 'A', MSG); // A::direct_name called, through A reference

    return 0;
}

// READ: 扩展阅读-纯虚、抽象 <https://zh.cppreference.com/w/cpp/language/abstract_class>
// READ: 扩展阅读-虚继承 <https://zh.cppreference.com/w/cpp/language/derived_class>
