#pragma once
#include <iostream>

namespace techyB
{
    class TC_Memory
    {
    private:
        class ListElem
        {
        private:
            int x;
            static int objCount;

        public:
            ListElem(const int para = 0) : x(para)
            {
                objCount++;
                std::cout << "constructor for obj " << objCount << std::endl;
            }

            ListElem& operator=(const ListElem &rhs)
            {
                x = rhs.x;
                std::cout << "= operator for obj " << objCount << std::endl;
                return *this;
            }
            ListElem(const ListElem &rhs) : x(rhs.x)
            {
                std::cout << "copy constructor for obj " << objCount << std::endl;
            }
            operator int() const
            {
                return x;
            }
        };

    public:
        TC_Memory() = default;
        void basicCopyDemo();
        void advancedMemoryMovement();
    };
} // namespace techyB
