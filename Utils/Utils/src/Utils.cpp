#include "Utils.h"

// Convert android::String16 to UTF-8
std::string toString(android::String16 text)
{
    std::string string = android::String8(text).string();
    return string;
}