#include <iostream>
#include <memory>


int main() {
    std::unique_ptr<int> p1(new int(5));
    std::unique_ptr<int> p2 = std::move(p1);
    std::cout << *p2 << std::endl;
    return 0;
}