#include <vector>

#ifdef GENERATE_DECLARATION_FOR
#define SIGNATURE GENERATE_DECLARATION_FOR

#define IMPL_DECLARATION(name, ...) \
{ \
    __VA_ARGS__ \
}; \
const char* enumString(name e); \
template<typename T> \
const std::vector<T> enumValues(); \
template<typename T> \
int enumCount();

#define ENUM_CLASS(name, ...) \
enum class name IMPL_DECLARATION(name, __VA_ARGS__)

#define ENUM_CLASS_WITH_TYPE(name, type, ...) \
enum class name : type IMPL_DECLARATION(name, __VA_ARGS__)

#define ENUM_PLAIN(name) \
name,

#define ENUM_VALUE(name, value) \
name = value,

SIGNATURE

#undef IMPL_DECLARATION
#undef ENUM_CLASS
#undef ENUM_CLASS_WITH_TYPE
#undef ENUM_PLAIN
#undef ENUM_VALUE

#undef SIGNATURE
#undef GENERATE_DECLARATION_FOR
#endif
