1#include <semaphore>
2
3class Foo {
4    std::binary_semaphore s1{0}, s2{0};
5public:
6    void first(function<void()> printFirst) {
7        printFirst();
8        s1.release();
9    }
10    void second(function<void()> printSecond) {
11        s1.acquire();
12        printSecond();
13        s2.release();
14    }
15    void third(function<void()> printThird) {
16        s2.acquire();
17        printThird();
18    }
19};