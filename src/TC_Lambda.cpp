#include <TC_Lambda.h>
#include <iostream>

std::ostream &operator<<(std::ostream &out, const techyB::TC_Lambda::LambdaParam &paramObj)
{
    return out << "{ paramObj.a : " << paramObj.a << ", paramObj.b : " << paramObj.b
               << ",  address : " << &paramObj << " }" << std::endl;
}

namespace techyB
{
    void TC_Lambda::forEachItem(const std::vector<int> &vec, void (*func)(int))
    {
        for (auto val : vec)
            func(val);
    }

    void TC_Lambda::forEachItemFunctional(const std::vector<int> &vec, std::function<void(int)> func)
    {
        for (auto val : vec)
            func(val);
    }

    void TC_Lambda::basicLambdaDemo()
    {
        const std::vector<int> myVec = {1, 37, 22, 57};
        auto lambdaVar = [](int value)
        {
            std::cout << "vector value : " << value << std::endl;
        };
        std::cout << "printing vector with lambda assigned to fpointer* : " << std::endl;
        forEachItem(myVec, lambdaVar);

        // This would fail since conversion from lambda with
        // capture to old function pointer is impossible
        // use std::function instead like below
        // forEachItem(myVec, [](int value)
        // { std::cout << "vector value : " << value << std::endl; });

        // however this works with std::function
        std::cout << "printing vector with lambda assigned to std::function : " << std::endl;
        forEachItemFunctional(myVec, lambdaVar);
    }

    void TC_Lambda::basicLambdaValuePassingDemo()
    {
        // Lambda value passage demo

        // context variables
        int a = 5;
        float b = 6.67f;
        LambdaParam paramObj;

        std::cout << "Context variables : " << std::endl;
        std::cout << "values : [ a : " << a << ", b : " << b
                  << ", paramObj : " << paramObj << std::endl;
        std::cout << std::endl
                  << std::endl;

        std::cout << "Context variable addresses : " << std::endl;
        std::cout << "addresses : [ &a : " << &a << ", &b : " << &b
                  << ", &paramObj : " << &paramObj << std::endl;
        // construct lambda capturing all values in context being passed by value
        auto func1 = [=]()
        {
            std::cout << "** printing objects available =>" << std::endl
                      << std::endl;
            std::cout << "values [ a : " << a << ", b : " << b << ", paramObj : " << paramObj << " ]" << std::endl;
            std::cout << "Addresses [ &a : " << &a << ", &b : " << &b << " ]" << std::endl;
        };
        std::cout << std::endl
                  << std::endl;
        std::cout << "========= Lambda - pass by value =============" << std::endl;
        func1();

        // construct lambda capturing all values in context being passed by reference
        auto func2 = [&]()
        {
            std::cout << "** printing objects available =>" << std::endl
                      << std::endl;
            std::cout << "values [ a : " << a << ", b : " << b << ", paramObj : " << paramObj << " ]" << std::endl;
            std::cout << "Addresses [ &a : " << &a << ", &b : " << &b << " ]" << std::endl;
        };
        std::cout << std::endl
                  << std::endl;
        std::cout << "========= Lambda - pass by reference =========" << std::endl;
        func2();

        // letts make const variables

        int x = 42;
        int y = 10;
        const int &xref = x;

        auto func3 = [xref, &y]()
        {
            std::cout << "Variables : ";
            // std::cout << " x = " << x; wont compile not explicitly captured
            std::cout << " y = " << y;
            std::cout << " xref = " << xref << std::endl
                      << std::endl;
            y = 25;
            // xref = 108; //would throw compile error since it's const ref
            std::cout << "Variables after modification: ";
            std::cout << " y = " << y;
            std::cout << " xref = " << xref << std::endl;
        };
        std::cout << std::endl
                  << std::endl;
        std::cout << "========= Lambda - explicit capture and const access =========" << std::endl;
        func3();
        std::cout << std::endl
                  << std::endl;
        std::cout << "Context values after modifications : "
                  << "[ x : " << x << ", y : " << y
                  << ", xref : " << xref << std::endl;

        // another example with lambda that returns
        int x1 = 5;
        const int y1 = 75;
        const int b1 = [&]() -> int
        {
            return y1;
        }();

        std::cout << std::endl
                  << std::endl;
        std::cout << "values after invoke :  x1 = " << x1 << ", b1 : " << b1 << std::endl;

        std::cout << std::endl
                  << std::endl;

        std::cout << "Demo accessing labda_access_member of class this class" << std::endl;
        std::cout << "labda_access_member in class : " << labda_access_member << std::endl;

        auto func4 = [&]() 
        {
            std::cout << "labda_access_member in lambda : " << labda_access_member << std::endl;
        };

        func4();
        std::cout << "labda_access_member in class : " << labda_access_member << std::endl;
    }

} // namespace techyB
