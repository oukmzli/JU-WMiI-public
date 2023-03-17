#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "================================\n№2:\n\n";
    
    const int LENGHT = 15;
    string array[LENGHT] = {"55555", "22", "333", "55555", "88888888", "333", "88888888", "88888888", "333", "333"};
    unsigned arrLenght = 0;
    
    // dokladna dlugosc tablicy i jej wypisywanie
    cout << "array:\n";
    for (int i = 0; i < LENGHT; ++i) {
        if ((array[i]).size() != 0) {
            cout << array[i] + " ";
            ++arrLenght;
        }
    }
    
    cout << "\n\n";
    
    // wyszukiwana dlugosc napisu
    int tempSize = 0, size = 0;
    int tempCounter = 0, counter = 0;
    for (int i = 0; i < arrLenght; ++i) {
        tempSize = (int)array[i].size();
        tempCounter = 0;
        for (int j = 0; j < arrLenght; ++j) {
            if (array[j].size() == tempSize) ++tempCounter;
        }
        
        if (counter < tempCounter) { size = tempSize; counter = tempCounter; }
    }
    
    // sortowanie tablicy
    for (int i = 0; i < arrLenght; ++i) {
        if (array[i].size() == size) {
            for (int j = 0; j < i; ++j)
                swap(array[j], array[i]);
        }
    }
    
    cout << "sorted by largest element array:\n";
    for (int i = 0; i < arrLenght; ++i)
        cout << array[i] + " ";
    
    /* ================================================================================= */
    /* ================================================================================= */
    /* ================================================================================= */
    /* ================================================================================= */
    
    cout << "\n================================\n№1:\n\n";
    
    char nowe[] = "nowe";
    char inStr[] = "111 111 aaa bbb ccc ddd 222 222 eee 333 333 fff";
    cout << inStr << "\n";
    
    // index pierwszego i ostatniego "do"
    int firstIndex{0}, lastIndex{0};
    bool firstDo = 1;
    for (int i = 0; i < strlen(inStr); ++i) {
        if (inStr[i] == 'd' && inStr[i + 1] == 'o') {
            if(firstDo) { firstIndex = i; firstDo = 0; }
            lastIndex = i + 2;
        }
    }
    
    // zamiana obszaru do---do na "nowe";
    int outLenght = (int)strlen(inStr) - (lastIndex - firstIndex) + 5;
    char outStr[outLenght];
    
    int outIndex = 0;
    for (int i = 0; i < strlen(inStr); ++i) {
        // obszar przed pierwszym "do"
        if (i < firstIndex) outStr[outIndex++] = inStr[i];
        
        // obszar po ostatnim "do"
        else if (i >= lastIndex) outStr[outIndex++] = inStr[i];
        
        // obszar pomiedzy dwoma "do", zamiana na "nowe";
        else {
            for (int j = 0; j < strlen(nowe); ++j)
                outStr[outIndex++] = nowe[j];
            i += lastIndex - firstIndex - 1;
        }
    }
    
    // ustalenie ostatniego elementu outStr jako '\0' dla poprawnego wypisywania za pomoca cout.
    outStr[outLenght - 1] = '\0';
    cout << outStr;
    
    cout << "\n\n";
    return 0;
}
