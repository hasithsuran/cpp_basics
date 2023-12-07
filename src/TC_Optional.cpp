#include <TC_Optional.h>

namespace techyB
{
    namespace essentials {

        namespace OptionalDemo {
            void runClient() {
                long num = 43;
                auto res = OptionalTester::getLowestFactor(num);
                if (res.has_value()) std::cout << "Lowest factor for " << num << ": " << res.value() << std::endl;
                else std::cout << "value " << num << " is a prime!" << std::endl;
            }
        }

    }
}