// Denys Kyrychenko
#include <iostream>
using namespace std;

int main() {
    unsigned setsNumber; cin >> setsNumber;
    int i = 0;
    
    while (setsNumber > 0) {
        
        int arrayLenght; cin >> arrayLenght;
        --arrayLenght;
        int array[arrayLenght];
        
        i = 0;
        while (i <= arrayLenght) { cin >> array[i]; i++; }
        
        i = 0;
        while (i <= arrayLenght) { cout << array[i] << " "; i++; }
        cout << endl;
        
        char operation;
        
        
        do {
            cin >> operation;
            if (operation != 'F') {
                
                int firstElement, fragmentLenght;
                cin >> firstElement >> fragmentLenght;
                
                
                while (firstElement > arrayLenght) firstElement -= (arrayLenght + 1);
                while (firstElement < 0) firstElement += (arrayLenght + 1);
                
                int arrayFragments;
                if (fragmentLenght > 0) arrayFragments = (arrayLenght + 1) / fragmentLenght;
                else if (-fragmentLenght > 0) arrayFragments = (arrayLenght + 1) / (-fragmentLenght);
                else arrayFragments = 0;
                
                
                int fragmentIndexLenght = fragmentLenght + firstElement - 1;
                if (fragmentLenght < 0) fragmentIndexLenght = -fragmentLenght + firstElement - 1;
                if (fragmentIndexLenght > arrayLenght) fragmentIndexLenght -= (arrayLenght + 1);
                
                // Odwracanie
                if (operation == 'R' && fragmentLenght <= arrayLenght + 1 && fragmentLenght > 0) {
                    while (arrayFragments > 0) {
                        i = 0;
                        int j = firstElement;
                        
                        while (i < fragmentLenght/2) {
                            if ((fragmentIndexLenght - i) < 0) swap(array[j], array[(arrayLenght + 1) - i]);
                            else swap(array[j], array[fragmentIndexLenght - i]);
                            
                            ++j; ++i;
                            if (j > arrayLenght) j -= (arrayLenght + 1);
                        }
                        
                        firstElement = fragmentIndexLenght + 1;
                        if (firstElement > arrayLenght) firstElement -= (arrayLenght + 1);
                        
                        fragmentIndexLenght += fragmentLenght;
                        if (fragmentIndexLenght > arrayLenght) fragmentIndexLenght -= (arrayLenght + 1);
                        
                        --arrayFragments;
                    }
                }
                
                
                // Przesuniecie
                if (operation == 'M') {
                    int shift; cin >> shift;
                    
                    if (fragmentLenght != 0) {
                        if (fragmentLenght > arrayLenght) fragmentLenght = arrayLenght + 1;
                        
                        if (shift > 0) shift = shift%fragmentLenght;
                        if (shift < 0) shift = -(-shift%fragmentLenght);
                        
                        ++arrayFragments;
                        while (arrayFragments > 0 && fragmentLenght != 0) {
                            i = 0;
                            while (i != shift) {
                                
                                if (shift >= 0) {
                                    
                                    int j = fragmentIndexLenght - 1;
                                    if (j < 0) j += arrayLenght + 1;
                                    if (j > arrayLenght) j -= (arrayLenght + 1);
                                    
                                    int temp = array[fragmentIndexLenght];
                                    
                                    int k = 0;
                                    while (k < (fragmentLenght - 1)) {
                                        if (j < 0) j += arrayLenght + 1;
                                        if ((j + 1) > arrayLenght) array[j - arrayLenght] = array[j];
                                        else array[j + 1] = array[j];
                                        --j; ++k;
                                    }
                                    array[firstElement] = temp;
                                    ++i;
                                }
                                
                                if (shift < 0) {
                                    
                                    int j = firstElement;
                                    
                                    int temp = array[firstElement];
                                    
                                    int k = 0;
                                    while (k < (fragmentLenght - 1)) {
                                        if (j > arrayLenght) j -= arrayLenght + 1;
                                        if ((j + 1) > arrayLenght) array[j] = array[j - arrayLenght];
                                        else array[j] = array[j + 1];
                                        ++j; ++k;
                                    }
                                    array[fragmentIndexLenght] = temp;
                                    --i;
                                }
                            }
                            
                            --arrayFragments;
                            if (arrayFragments == 1) fragmentLenght = (arrayLenght + 1) % fragmentLenght;
                            
                            firstElement = fragmentIndexLenght + 1;
                            if (firstElement > arrayLenght) firstElement -= (arrayLenght + 1);
                            
                            fragmentIndexLenght += fragmentLenght;
                            if (fragmentIndexLenght > arrayLenght) fragmentIndexLenght -= (arrayLenght + 1);
                        }
                    }
                }
                
                
                // Zamiana
                if (operation == 'C' && arrayFragments > 1 && fragmentLenght <= arrayLenght) {
                    int fragmentsPairs = arrayFragments / 2;
                    while (fragmentsPairs > 0) {
                        
                        i = 0;
                        int j = firstElement;
                        while (i < fragmentLenght) {
                            if (j > arrayLenght) j -= arrayLenght + 1;
                            if ((j + fragmentLenght) > arrayLenght) {
                                swap(array[j], array[(j + fragmentLenght) - (arrayLenght + 1)]);
                            } else swap(array[j], array[j + fragmentLenght]);
                            ++i; ++j;
                        }
                        --fragmentsPairs;
                        firstElement += fragmentLenght * 2;
                        if (firstElement > arrayLenght) firstElement -= (arrayLenght + 1);
                        
                        fragmentIndexLenght += (fragmentLenght * 2);
                        if (fragmentIndexLenght > arrayLenght) fragmentIndexLenght -= (arrayLenght + 1);
                    }
                }
                
                
                // Sortowanie
                if (operation == 'S' && fragmentLenght != 0) {
                    bool fragmentDirection = true;
                    if (fragmentLenght < 0) { fragmentDirection = false; fragmentLenght *= -1; }
                    
                    if (fragmentLenght > arrayLenght+1) {
                        fragmentLenght = arrayLenght + 1;
                        if (firstElement > 0) ++arrayFragments;
                    }
                    
                    ++arrayFragments;
                    while (arrayFragments > 0 && fragmentLenght != 0) {
                        
                        bool flag;
                        do {
                            flag = false;
                            i = 0;
                            int j = firstElement;
                            while (i < fragmentLenght - 1) {
                                if (j > arrayLenght) j -= arrayLenght + 1;
                                if ((j + 1) > arrayLenght) {
                                    if (fragmentDirection) {
                                        if (array[j] > array[j - arrayLenght]) {
                                            swap(array[j], array[j - arrayLenght]);
                                            flag = true;
                                        }
                                    } else {
                                        if (array[j] < array[j - arrayLenght]) {
                                            swap(array[j], array[j - arrayLenght]);
                                            flag = true;
                                        }
                                    }
                                } else {
                                    if (fragmentDirection) {
                                        if (array[j] > array[j + 1]) {
                                            swap(array[j], array[j + 1]);
                                            flag = true;
                                        }
                                    } else {
                                        if (array[j] < array[j + 1]) {
                                            swap(array[j], array[j + 1]);
                                            flag = true;
                                        }
                                    }
                                }
                                ++i; ++j;
                            }
                        } while (flag);
                        
                        --arrayFragments;
                        if (arrayFragments == 1) fragmentLenght = (arrayLenght + 1) % fragmentLenght;
                        
                        firstElement = fragmentIndexLenght + 1;
                        if (firstElement > arrayLenght) firstElement -= (arrayLenght + 1);
                        
                        fragmentIndexLenght += fragmentLenght;
                        if (fragmentIndexLenght > arrayLenght) fragmentIndexLenght -= (arrayLenght + 1);
                    }
                }
            }
        } while (operation != 'F');
        
        i = 0;
        while (i <= arrayLenght) { cout << array[i] << " "; ++i; }
        
        cout << endl;
        --setsNumber;
    }
    
    return 0;
}
