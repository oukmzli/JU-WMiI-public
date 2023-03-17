//Denys Kyrychenko
#include <iostream>

int main() {
    int setAmount;
    float firstVariable, secondVariable, thirdVariable, fourtVariable, fifthVariable, maxValue = 0.0, minValue = 0.0;
    std::cin >> setAmount;
    
    for (int i = 0; i < setAmount; i++) {
        std::cin >> firstVariable >> secondVariable >> thirdVariable >> fourtVariable >> fifthVariable;
        minValue = firstVariable; maxValue = firstVariable;
        for (int j = 0; j < setAmount; j++) {
            firstVariable > maxValue ? maxValue = firstVariable : maxValue;
            secondVariable > maxValue ? maxValue = secondVariable : maxValue;
            thirdVariable > maxValue ? maxValue = thirdVariable : maxValue;
            fourtVariable > maxValue ? maxValue = fourtVariable : maxValue;
            fifthVariable > maxValue ? maxValue = fifthVariable : maxValue;
            
            firstVariable < minValue ? minValue = firstVariable : minValue;
            secondVariable < minValue ? minValue = secondVariable : minValue;
            thirdVariable < minValue ? minValue = thirdVariable : minValue;
            fourtVariable < minValue ? minValue = fourtVariable : minValue;
            fifthVariable < minValue ? minValue = fifthVariable : minValue;
        }
        std::cout << minValue << " " << maxValue << " " <<  (firstVariable + secondVariable + thirdVariable + fourtVariable + fifthVariable) / 5.0 << std::endl;
    }
    
    return 0;
}
