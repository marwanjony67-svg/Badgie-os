#ifndef UTILS_HPP
#define UTILS_HPP

inline int stringLength(const char* str) {
    int len = 0;
    while (str[len]) len++;
    return len;
}

#endif
