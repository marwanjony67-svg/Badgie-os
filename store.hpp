#ifndef STORE_HPP
#define STORE_HPP

#include "screen.hpp"

class Store {
public:
    static void open() {
        Screen::print("\n--- BudgieOS Store ---\n");
        Screen::print("Available: 1. Browser 2. Media Player\n");
    }
};

#endif
