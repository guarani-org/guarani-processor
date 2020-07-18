#include <iostream>
#include <cmdline_t.h>

int main(int ac, char **av) {
    std::cout << "Hello, world!\n";
    if (!cmdline_t::get().parse(ac, av)) {
        return -1;
    }

    return 0;
}
