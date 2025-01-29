#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> number)
{
    *number = 20;
    std::cout << *number << " " << number.use_count() << std::endl;
}

int main() {
    std::shared_ptr<int> number = std::make_shared<int>(10);
    
    std::cout << *number << " " << number.use_count() << std::endl;
    foo(number);
    std::cout << *number << " " << number.use_count() << std::endl;

    return 0;
}