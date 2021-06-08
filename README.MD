### Enum Tools
Enum tools is a header based system to get some useful functions for enum classes in C++. In particular the header provides 3 functions: *enumString()*, *enumValues()*, *enumCount()* for stringifying enum values, getting all enum values, getting count of all enum values.

#### Usage
To use enum tools all you need to do is use the __enum_tools.hpp__ header. But this is not a header in a traditional sense. While traditional headers are intended to be actually included only once, enum_tools.hpp is intended to be included multiple times. This is because enum_tools.hpp uses preprocessing macros to generate the enum functions.

To use the header first define your enum with a preprocessing macro *signature*. For example the following are some example of signatures (note there is only one comma)

```
#define my_signature_1 \
enum_class(A, \
    enum_plain(x) \
    enum_value(y, 5) \
)
```
This is a signature for the following enum:
```
enum class A {
    x, y = 5
}
```
For a enum that is based on a type you can use *enum_class_with_type()* (see the example code for details)

After defining this signature you have to use the following code for generating the enum and the function declarations:
```
#define GENERATE_DECLARATION_FOR my_signature_1
#include "enum_tools.hpp"
```
And to define the functions use this:
```
#define GENERATE_DEFINITION_FOR my_signature_1
#include "enum_tools.hpp"
```

The header uses the "GENERATE_DECLARATION_FOR" and "GENERATE_DEFINITION_FOR" defines to use the signature to generate required code. For more example see the example codes.

The header gives 3 function:
1. enumString(e) : function that stringifies the input enum value
2. enumValues\<enum type\>() : function that returns a const vector of all enum values of a type
3. enumCount\<enum type\>() : function that returns count of enum values of a type

#### Feedback
Any feedback is appreciated.