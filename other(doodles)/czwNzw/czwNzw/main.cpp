#include <iostream>
#include "inWordСonverter.hpp"
using namespace std;

int count(int n) {
    int counter {0};
    while (n > 0) { counter++; n /= 10; }
    return counter;
}

int main() {
    int number, numberLenght;
    
     do {
         cout << "Wpisz liczbe: "; cin >> number;
         numberLenght = count(number);
         if (numberLenght > 4) cout << "Maksymalna dlugosc liczby - 4 znaki." << endl;
         else if (numberLenght <= 0) cout << "Liczba musi mieс co najmniej jeden znak." << endl;
     } while (numberLenght <= 0 || numberLenght > 4);
    
    switch (numberLenght) {
        case 1: cout << singleDigit(number); break;
        case 2: cout << twoDigit(number); break;
        case 3: cout << threeDigit(number); break;
        case 4: cout << fourDigit(number); break;
        default: break;
    }
    
    cout << endl << endl;
    return 0;
}
