//Denys Kyrychenko
#include <iostream>
int main() {
    int value, divider;
    unsigned int checksAmount;
    
    std::cin >> value; std::cin >> checksAmount;
    
    bool output[checksAmount];
    
    for (int i = checksAmount; i > 0; --i) {
        std::cin >> divider;
        value % divider == 0 ? output[i] = true : output[i] = false;
    }
    
    for (int i = checksAmount; i > 0; --i) {
        output[i] ? std::cout << "TAK" << std::endl : std::cout << "NIE" << std::endl;
    }
    
    return 0;
}
