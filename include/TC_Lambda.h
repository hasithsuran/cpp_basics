#pragma once
#include <vector>
#include <functional>
#include <iostream>

namespace techyB
{

    class TC_Lambda
    {
    private:
        // would accept lambdas (without capture) as well as function pointers
        void forEachItem(const std::vector<int> &vec, void (*func)(int));
        // would accpt all
        void forEachItemFunctional(const std::vector<int> &vec, std::function<void(int)> func);
        int labda_access_member {17}; // this would be access in one of the lambdas

    public:
        class LambdaParam
        {
        public:
            int a;
            float b;
            LambdaParam()
            {
                this->a = 5;
                this->b = 25;
            }
            LambdaParam(const LambdaParam &param)
            {
                std::cout << "copy constructing param object!" << std::endl;
                this->a = param.a;
                this->b = param.b;
            }
        };

        TC_Lambda() {}
        void basicLambdaDemo();
        void basicLambdaValuePassingDemo();
    };

} // namespace techyB

std::ostream &operator<<(std::ostream &out, const techyB::TC_Lambda::LambdaParam &paramObj);
