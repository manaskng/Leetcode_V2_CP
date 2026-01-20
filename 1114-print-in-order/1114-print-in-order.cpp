#include <semaphore>

class Foo {
    std::binary_semaphore s1{0}, s2{0};
public:
    void first(function<void()> printFirst) {
        printFirst();
        s1.release();
    }
    void second(function<void()> printSecond) {
        s1.acquire();
        printSecond();
        s2.release();
    }
    void third(function<void()> printThird) {
        s2.acquire();
        printThird();
    }
};