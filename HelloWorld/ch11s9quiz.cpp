#include <iostream>

template <int N>
constexpr int factorial() {
    static_assert(N >= 0, "factorial: N must be >= 0");

    int product {1};
    for (int i {2}; i <= N; i++)
        product *= i;

    return product;
}

template <int N>
constexpr int factorial2()
{
    static_assert(N >= 0);

    int product { 1 };
    for (int i { 2 }; i <= N; ++i)
        product *= i;

    return product;
}

template <int N>
constexpr int factorial3() {
    static_assert(N >= 0);

    int num {N}, product {1};
    while (num >= 2) {
        product *= num;
        num--;
    }
    return product;
}

// THIS method DOES NOT WORK!  
// N is not a variable, cannot be decremented like a variable!
// ex: if the given N is 5, N-- will always produce 4 which makes this an infinite loop!
//   (decrementing N will also give an error)
// also, if the given N is 5, while (N > 0) will always be true! 
// also we're doing 5*=4 which gives 20, then 20-- is 19, then 19*=18 is ... infinite loop
// and leads to overflow in the int variable named product
template <int N>
constexpr int factorialOriginal() {
    static_assert(N >= 0);



    if constexpr (N > 0) {
        int product {N};
        while (product >= 2) {
            product *= (product - 1);
            product--;
        }
        return product;
    }
    return 1;
}

void ch11s9quiz() {
    static_assert(factorial3<0>() == 1);
    static_assert(factorial3<3>() == 6);
    static_assert(factorial3<5>() == 120);
    std::cout << "\nstatic asserts passed\n";
    
    // factorial<-3>(); // should fail to compile
}