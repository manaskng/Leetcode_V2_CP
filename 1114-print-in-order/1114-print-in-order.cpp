class Foo {
public:
     atomic<int>state;
    Foo() {
       
        state=1;
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        state=2;
    }


    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(state!=2);
        printSecond();
        state=3;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while(state!=3);
        printThird();
    }
};