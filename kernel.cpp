#include "screen.hpp"
#include "keyboard.hpp"
#include "store.hpp"

extern "C" void kernel_main() {
    Screen::clear();
    Screen::print("=== Welcome to BudgieOS v0.4 ===\n");
    Screen::print("Initializing system modules...\n");

    while(true) {
        Screen::print("\n1. Open Store\n2. System Info\n> ");
        char cmd = Keyboard::readChar();
        if(cmd == '1') {
            Store::open();
        } else if(cmd == '2') {
            Screen::print("\nBudgieOS Real Kernel - C++ & Assembly\n");
        }
    }
}
