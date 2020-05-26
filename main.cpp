/*Use double-check because of unavailability to include iostream inside the function.
If iostream is included at the beginning of the file it will be redundant in case of
USE_STRING_FUNC is set*/

#ifdef USE_STRING_FUNC
    #include "lib/include/print.h"
#else
    #include "lib/include/multiplier.h"
    #include <iostream>
#endif

int main(int argc, char** argv)
{
    #ifdef USE_STRING_FUNC
        std::string message("C++");
        printString(message);
    #else
        const int magickNumber = 10;
        std::cout << makeDouble(magickNumber);
    #endif
        
    return 0;
}