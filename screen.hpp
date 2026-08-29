#ifndef SCREEN_HPP
#define SCREEN_HPP

class Screen {
public:
    static void clear() {
        // Clear screen logic
    }
    static void print(const char* str) {
        char* vidmem = (char*) 0xb8000;
        while(*str) {
            *vidmem++ = *str++;
            *vidmem++ = 0x07;
        }
    }
};

#endif
