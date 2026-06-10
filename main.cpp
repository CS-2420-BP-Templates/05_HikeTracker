#include <iostream>
#include "Collection.h"

int main() {
    std::cout << "Hike Tracker!" << std::endl;
    Collection<string, 5> c;
    c.add("Hello");
    c.add("Bye");
    cout << c << endl;

    return 0;
}
