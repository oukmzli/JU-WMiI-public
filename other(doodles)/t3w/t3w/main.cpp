//Denys Kyrychenko
#include <iostream>
using namespace std;

int main() {
    int setAmount;
    float variable, maxValue = 0.0, minValue = 0.0, summation = 0.0;
    cin >> setAmount;
    int i = 0, j = 0;
    
    while (i < setAmount) {
        j = 0;
        while (j < 5) {
            cin >> variable;
            if (variable > maxValue) maxValue = variable;
            if (variable < minValue) minValue = variable;
            if (j == 0) minValue = variable;
            summation += variable;
            j++;
        }
        cout << minValue << " " << maxValue << " " <<  summation / 5.0 << endl;
        minValue = 0.0; maxValue = 0.0; summation = 0.0;
        i++;
    }
    
    return 0;
}
