#ifdef GENERATE_DECLARATION_FOR
#define __SIGNATURE GENERATE_DECLARATION_FOR

#define __IMPL_DECLARATION(name, ...) \
{ \
    __VA_ARGS__ \
}; \
char const * enumString(name e); \
template<typename T> \
std::vector<T> const enumValues(); \
template<typename T> \
int enumCount();

#define ENUM_CLASS(name, ...) \
enum class name __IMPL_DECLARATION(name, __VA_ARGS__)

#define ENUM_CLASS_WITH_TYPE(name, type, ...) \
enum class name : type __IMPL_DECLARATION(name, __VA_ARGS__)

#define ENUM_PLAIN(name) \
name,

#define ENUM_VALUE(name, value) \
name = value,

__SIGNATURE

#undef __IMPL_DECLARATION
#undef ENUM_CLASS
#undef ENUM_CLASS_WITH_TYPE
#undef ENUM_PLAIN
#undef ENUM_VALUE

#undef __SIGNATURE
#undef GENERATE_DECLARATION_FOR
#endif


#ifdef GENERATE_DEFINITION_FOR
#define __SIGNATURE GENERATE_DEFINITION_FOR

#define ENUM_CLASS_WITH_TYPE(name, type, ...) \
ENUM_CLASS(name, __VA_ARGS__)

#define ENUM_VALUE(name, value) \
ENUM_PLAIN(name)

#define ENUM_CLASS(name, ...) \
char const * enumString(name e){ \
    using enumtype = name; \
    switch(e){ \
        __VA_ARGS__ \
    } \
    throw "Invalid enum value"; \
    return 0; \
}

#define ENUM_PLAIN(name) \
case enumtype :: name : \
    return #name ; \

__SIGNATURE

#undef ENUM_CLASS
#undef ENUM_PLAIN

// TODO maybe consider a global vector?

#define ENUM_CLASS(name, ...) \
template<> \
std::vector<name> const enumValues<name>() { \
    using enumtype = name; \
    return { __VA_ARGS__ }; \
}

#define ENUM_PLAIN(name) \
enumtype :: name ,

__SIGNATURE

#undef ENUM_CLASS
#undef ENUM_PLAIN

#define ENUM_CLASS(name, ...) \
template<> \
int enumCount<name>() { \
    return 0 __VA_ARGS__ ; \
}

#define ENUM_PLAIN(name)  \
+ 1

__SIGNATURE

#undef ENUM_CLASS
#undef ENUM_PLAIN

#undef ENUM_CLASS_WITH_TYPE
#undef ENUM_VALUE

#undef __SIGNATURE
#undef GENERATE_DEFINITION_FOR
#endif