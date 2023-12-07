#pragma once

#include <iostream>
#include <variant>
#include <string_view>
#include <vector>

namespace techyB
{
namespace essentials {

    namespace VariantDemo {
        
        class Animal {
            private:
                std::string_view m_name;
                std::string_view m_sound;
            public:
                Animal() = delete;
                Animal(const std::string_view name, const std::string_view sound): m_name(name), m_sound(sound) {}
                void speak() {
                    std::cout << m_name << " says " << m_sound << std::endl;
                }
        };

        class Cat : public Animal {
            public:
                Cat(const std::string_view name): Animal(name, "Meow") {}
        };

        class Dog : public Animal {
            public:
                Dog(const std::string_view name) : Animal(name, "Warf") {}
        };

        void runClient();
    }
}

}