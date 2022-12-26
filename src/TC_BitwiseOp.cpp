#include <TC_BitwiseOp.h>
#include <iostream>
#include <bitset>
#include <iomanip>

namespace techyB
{
    void TC_BitwiseOp::performBitLeftShift()
    {
        std::cout << "=========== Performing left bit shift operations ============" << std::endl;
        // each left shift multiplies decimal value by 2^n
        // where n is number of bits shifted in the operation
        std::cout << "Number before shifting : " << std::endl;
        printNumMultiMode(shiftNum, BINARY | DECIMAL);

        shiftNum = static_cast<unsigned short int>(shiftNum << 1);
        std::cout << "Number after << 1 : " << std::endl;
        printNumMultiMode(shiftNum, BINARY | DECIMAL);

        shiftNum = static_cast<unsigned short int>(shiftNum << 3);
        std::cout << "Number after << 3 : " << std::endl;
        printNumMultiMode(shiftNum, BINARY | DECIMAL);

        // left most bit has shifted to the most significant bit location
        // shifting left beyond this pont would break value increase rule explained above
        shiftNum = static_cast<unsigned short int>(shiftNum << 1);
        std::cout << "Number after << 1 : " << std::endl;
        printNumMultiMode(shiftNum, BINARY | DECIMAL);

        std::cout << "Note: most significant bit with 1 is lost and " << std::endl;
        std::cout << "could not recover with left shift again" << std::endl;
    }

    void TC_BitwiseOp::performBitRightShift()
    {
        std::cout << "=========== Performing right bit shift operations ============" << std::endl;
        // each right shift divides decimal value by 2^n
        // where n is number of bits shifted in the operation
        std::cout << "Number before right shifting : " << std::endl;
        printNumMultiMode(rightShiftNum, BINARY | DECIMAL);

        rightShiftNum = static_cast<unsigned short int>(rightShiftNum >> 1);
        std::cout << "Number after >> 1 : " << std::endl;
        printNumMultiMode(rightShiftNum, BINARY | DECIMAL);
    }

    void TC_BitwiseOp::doLogicalBitwiseOperation()
    {
        std::cout << "============ initial values of variables =============" << std::endl;
        std::cout << std::endl;

        std::cout << std::setw(COLUMN_WIDTH) << "Initial value 1 : "
                  << std::setw(COLUMN_WIDTH) << std::bitset<8>(logicalOp1)
                  << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "Initial value 2 : "
                  << std::setw(COLUMN_WIDTH) << std::bitset<8>(logicalOp2)
                  << std::endl;
        std::cout << std::endl;

        // perform logical AND(&) betwen value 1 and value 2 at bit level
        std::cout << "============ logical AND operation =============" << std::endl;
        std::cout << std::endl;

        std::cout << std::setw(COLUMN_WIDTH) << "value 1 & value 2 : "
                  << std::setw(COLUMN_WIDTH) << std::bitset<8>(logicalOp1 & logicalOp2)
                  << std::endl;

        // perform logical OR(|) betwen value 1 and value 2 at bit level
        std::cout << "============ logical OR operation =============" << std::endl;
        std::cout << std::endl;

        std::cout << std::setw(COLUMN_WIDTH) << "value1 | value 2 : "
                  << std::setw(COLUMN_WIDTH) << std::bitset<8>(logicalOp1 | logicalOp2)
                  << std::endl;
        std::cout << std::endl;

        // perform logical XOR(^) betwen value 1 and value 2 at bit level
        std::cout << "============ logical XOR operation =============" << std::endl;
        std::cout << std::endl;

        std::cout << std::setw(COLUMN_WIDTH) << "value1 ^ value 2 : "
                  << std::setw(COLUMN_WIDTH) << std::bitset<8>(logicalOp1 & logicalOp2)
                  << std::endl;
        std::cout << std::endl;

        // perform logical NOT(~) for value 1 and value 2 at bit level
        std::cout << "============ logical NOT operation =============" << std::endl;
        std::cout << std::endl;

        std::cout << std::setw(COLUMN_WIDTH) << "~value1 : "
                  << std::setw(COLUMN_WIDTH) << std::bitset<8>(~logicalOp1)
                  << std::endl;
        std::cout << std::setw(COLUMN_WIDTH) << "~value2 : "
                  << std::setw(COLUMN_WIDTH) << std::bitset<8>(~logicalOp2)
                  << std::endl;
        std::cout << std::endl;
    }

    void TC_BitwiseOp::printNumberInBase(unsigned short int num, NUMBER_BASE base)
    {
        switch (base)
        {
        case TC_BitwiseOp::NUMBER_BASE::DECIMAL:
            std::cout << "data (dec) : " << std::showbase << std::dec << num << std::endl;
            break;
        case TC_BitwiseOp::NUMBER_BASE::HEX_DECIMAL:
            std::cout << "data (hex) : " << std::showbase << std::hex << num << std::endl;
            break;
        case TC_BitwiseOp::NUMBER_BASE::BINARY:
            std::cout << "data (bin) : " << std::showbase << std::bitset<16>(num) << std::endl;
            break;
        case TC_BitwiseOp::NUMBER_BASE::OCTAL:
            std::cout << "data (oct) : " << std::showbase << std::oct << num << std::endl;
            break;
        default:
            std::cerr << "Invalid base type passed. Could not perform the operation!" << std::endl;
            break;
        }
    }

    void TC_BitwiseOp::printNumMultiMode(unsigned short int num, VERBOSE_MODE verboseMode)
    {
        // demonstrates usage of bit masks
        if (verboseMode & NUMBER_BASE::DECIMAL)
        {
            printNumberInBase(num, DECIMAL);
        }
        if (verboseMode & NUMBER_BASE::BINARY)
        {
            printNumberInBase(num, BINARY);
        }
        if (verboseMode & NUMBER_BASE::HEX_DECIMAL)
        {
            printNumberInBase(num, HEX_DECIMAL);
        }
        if (verboseMode & NUMBER_BASE::OCTAL)
        {
            printNumberInBase(num, OCTAL);
        }
    }

} // namespace techyB
