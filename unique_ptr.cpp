#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> p1 {new int {100}}; // Creates a unique_ptr managing a new int initialized to 100
    std::cout << p1.get() << std::endl; // Prints the address of the managed object
    
    p1.reset(); // Resets p1, which deletes the managed object and sets p1 to nullptr
    
    if (p1) // This condition checks if p1 is not null, which it is after reset, so the inside of this if-statement won't execute
        std::cout << *p1 << std::endl; // This line would attempt to dereference a nullptr if it were reached, leading to undefined behavior
    
    return 0;
}
