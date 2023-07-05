#ifndef _H_TEST
#define _H_TEST

#include <iostream>

template<typename T>
class Test {
public:
    Test() {
        std::cout << "Initializing test\n";
    }

    T add (T a, T b);
};

template<>
int Test<int>::add(int a, int b) {
    return a + b;
}

template<>
float Test<float>::add(float a, float b) {
    return a + b;
}

#endif