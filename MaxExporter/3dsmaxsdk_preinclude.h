#define STRING2(x) #x
#define STRING(x) STRING2(x)
#define TODO(x) __FILE__ "(" STRING(__LINE__) "): TODO: "x

