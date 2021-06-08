#include <iostream>

// defining signature for enum day
#define DAY_SIGNATURE \
ENUM_CLASS(day, \
    ENUM_PLAIN(saturday)        \
    ENUM_PLAIN(sunday)          \
    ENUM_PLAIN(monday)          \
    ENUM_PLAIN(tuesday)         \
    ENUM_PLAIN(wednesday)       \
    ENUM_PLAIN(thursday)        \
    ENUM_PLAIN(friday)          \
)

// defining signature for enum color
#define COLOR_SIGNATURE \
ENUM_CLASS_WITH_TYPE(color, unsigned int, \
    ENUM_VALUE(red, 0xff0000)   \
    ENUM_VALUE(green, 0x00ff00) \
    ENUM_VALUE(blue, 0x0000ff)  \
)

// declaring day enum and it's tools
#define GENERATE_DECLARATION_FOR DAY_SIGNATURE
#include "enum_tools/enum_tools.hpp"

// declaring color enum and it's tools
#define GENERATE_DECLARATION_FOR COLOR_SIGNATURE
#include "enum_tools/enum_tools.hpp"




// defining day enum's tools
#define GENERATE_DEFINITION_FOR DAY_SIGNATURE
#include "enum_tools/enum_tools.hpp"

// defining color enum's tools
#define GENERATE_DEFINITION_FOR COLOR_SIGNATURE
#include "enum_tools/enum_tools.hpp"


int main(int argc, char const *argv[]) {

    // print enum values of day
    for(auto e : enumValues<day>()){
        std::cout<<enumString(e)<<std::endl;
    }
    std::cout<<"count of day : "<<enumCount<day>()<<std::endl;

    std::cout<<std::endl;

    // print enum values of color
    for(auto e : enumValues<color>()){
        std::cout<<enumString(e)<<std::endl;
    }
    std::cout<<"count of color : "<<enumCount<color>()<<std::endl;


    return 0;
}
