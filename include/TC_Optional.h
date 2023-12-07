#pragma once
#include <iostream>
#include <optional>

namespace techyB
{
namespace essentials {

    namespace OptionalDemo {

        class OptionalTester {
        public:
            // ------------- classic exampole without optional ------------------
            //struct FactorValue {
            //    long value;
            //    bool hasValue;
            //};

            //FactorValue getLowestFactor(long n) {
            //    FactorValue fv = { 0, false };
            //    for (long i = 2; i <= n / 2; i++) {
            //        if (n % i == 0) {
            //            fv.value = i;
            //            fv.hasValue = true;
            //            return fv;
            //        }
            //    }
            //    return fv;
            //}

            //------------- example updated to use optional --------------------

            static std::optional<long> getLowestFactor(long n) {
                for (long i = 2; i <= n / 2; i++) {
                    if (n % i == 0) {
                        return i;
                    }
                }
                return {};
            }

        };

        void runClient();
    }
}

}