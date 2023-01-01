#include <TC_Memory.h>
#include <cstring>
#include <algorithm> // for std::for_each, copy and copy_if
#include <numeric>   // for std::iota
#include <list>
#include <vector>
#include <iterator>

namespace techyB
{
    int TC_Memory::ListElem::objCount{0};

    void TC_Memory::basicCopyDemo()
    {
        const int BUFF_SIZE1 = 40;
        char dest_buff[BUFF_SIZE1];
        char src_buff[BUFF_SIZE1] = "Hello world";

        // copies from src_buff to dest until null \0 character is reached
        std::strcpy(dest_buff, src_buff);
        std::cout << "copying using strscpy(dst_buff, src_buff)" << std::endl;
        std::cout << std::endl;
        std::cout << "Source char array (src_buff) : " << src_buff << std::endl;
        std::cout << "copied char array (dest_buff): " << dest_buff << std::endl;
        std::cout << std::endl
                  << std::endl;

        std::cout << "Reset destination buffer using memset(dst_buff, '\\0, 40)" << std::endl;
        std::memset(dest_buff, '\0', BUFF_SIZE1);
        auto printArray = [](const char &ch)
        {
            std::cout << ", " << ch;
        };

        std::cout << "dest buffer initial raw content : " << std::endl;
        std::for_each(dest_buff, dest_buff + BUFF_SIZE1, printArray);
        std::cout << std::endl
                  << std::endl;

        std::strcpy(src_buff + strlen(src_buff) + 1, "welcome");
        char dest_buff2[BUFF_SIZE1];
        std::memcpy(dest_buff, src_buff, BUFF_SIZE1);
        std::cout << "copying using memscpy(dst_buff, src_buff2, 30)" << std::endl;
        std::cout << std::endl;
        std::cout << "dest buffer raw content after memcpy : " << std::endl;
        std::for_each(dest_buff, dest_buff + BUFF_SIZE1, printArray);
        std::cout << std::endl
                  << std::endl;

        std::strcpy(dest_buff2, src_buff);
        std::cout << "copying using strcpy(dst_buff2, src_buff2)" << std::endl;
        std::cout << std::endl;
        std::cout << "dest buffer raw content after strcpy : " << std::endl;
        std::for_each(dest_buff2, dest_buff2 + BUFF_SIZE1, printArray);
        std::cout << std::endl
                  << std::endl;
    }

    void TC_Memory::advancedMemoryMovement()
    {
        // 1) demo iota on linked list
        std::list<int> myList(10);
        // initialize list with values starting from 5 incrementing by 1
        std::iota(myList.begin(), myList.end(), 5);

        auto listPrinter = [](const auto &element)
        {
            std::cout << "element : " << element << std::endl;
        };

        // 2) demo for_each on list
        std::cout << "linked list content : " << std::endl;
        std::for_each(myList.begin(), myList.end(), listPrinter);
        std::cout << std::endl
                  << std::endl;

        // 3) demo iota on c style array
        const int BUFF_SIZE = 10;
        int intBuffer[BUFF_SIZE];
        std::iota(intBuffer, intBuffer + BUFF_SIZE, 4);

        // 4) demo for_each on basic C style array
        std::cout << "Array content : " << std::endl;
        std::for_each(intBuffer, intBuffer + BUFF_SIZE, listPrinter);

        std::cout << "Object list demonstration : " << std::endl;
        std::list<ListElem> objList(10);
        std::iota(objList.begin(), objList.end(), 1);

        std::cout << "Object list content : " << std::endl;
        std::for_each(objList.begin(), objList.end(), listPrinter);

        // 5) demo std::copy
        std::vector<int> fromVec(10);
        std::iota(fromVec.begin(), fromVec.end(), 0);
        std::vector<int> toVec;
        std::copy(fromVec.begin(), fromVec.end(), std::back_inserter(toVec));
        std::cout << "back inserted int vector content : " << std::endl;
        std::for_each(toVec.begin(), toVec.end(), listPrinter);

        // 6) copy to ostream
        std::cout << "std::copy to ostream_iterator, result :  " << std::endl;
        std::copy(toVec.begin(), toVec.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl
                  << std::endl;

        // 7) copy to ostream with predicate
        std::cout << "std::copy to ostream_iterator with predicate for even numbers, result :  " << std::endl;
        std::copy_if(toVec.begin(), toVec.end(),
                     std::ostream_iterator<int>(std::cout, " "),
                     [](const int x)
                     {
                         return (x % 2) == 0;
                     });
        std::cout << std::endl
                  << std::endl;
    }

} // namespace techyB
