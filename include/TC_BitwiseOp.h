#pragma once

namespace techyB
{

    class TC_BitwiseOp
    {
    private:
        //bitshifting varibles
        unsigned short int shiftNum{0xff0u};
        unsigned short int rightShiftNum{0xff0u};

        //bitwise logical operands
        unsigned char logicalOp1 {0x3};
        unsigned char logicalOp2 {0x5};

        //display formatting params
        const int COLUMN_WIDTH = 20;

        using VERBOSE_MODE = unsigned char;

    public:
        enum NUMBER_BASE
        {
            DECIMAL = 0x1,
            HEX_DECIMAL = 0x2,
            BINARY = 0x4,
            OCTAL = 0x8
        };

        TC_BitwiseOp() {}
        void performBitLeftShift();
        void performBitRightShift();
        void doLogicalBitwiseOperation();
        void printNumberInBase(unsigned short int num, NUMBER_BASE base);
        void printNumMultiMode(unsigned short int num, VERBOSE_MODE verboseMode);
    };

}
