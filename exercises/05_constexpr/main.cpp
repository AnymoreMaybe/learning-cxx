#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    if (i == 0) return 0;
    if (i == 1) return 1;
    
    unsigned long long a = 0; // fib(0)
    unsigned long long b = 1; // fib(1)
    unsigned long long result = 0;
    
    for (int j = 2; j <= i; ++j) {
        result = a + b; // fib(j) = fib(j-2) + fib(j-1)
        a = b;          // 更新 fib(j-2) 为下一轮的 fib(j-1)
        b = result;     // 更新 fib(j-1) 为下一轮的 fib(j)
    }
    return result;
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    auto ANS_N = 90;
    auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
