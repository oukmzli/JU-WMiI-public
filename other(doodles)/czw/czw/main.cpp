#include <iostream>
using namespace std;

void addressToInt (string dotAddress, int address[]) {
    string temp;
    int j {}, k {};
    for (int i = 0; i < dotAddress.size(); ++i) {
        if (dotAddress[i] == '.' || i == dotAddress.size() - 1) {
            string temp = dotAddress.substr(j, i); j = i + 1;
            address[k] = stoi(temp); ++k;
        }
    }
}

int main() {
    int ipv[2];//, mask[3], subnetwork[3];
    
    string aha = "255.222.222";
    addressToInt(aha, ipv);
    for (int i = 0; i < 6; ++i) {
        cout << ipv[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
