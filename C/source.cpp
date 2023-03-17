// Denys Kyrychenko
#include <iostream>

bool isUniwersum (int n) {
    if (n > 0 && n < 4096) return true;
    return false;
}

void Cardinality (int arr[], int *lenght) {
    *lenght = 0;
    while (arr[*lenght] != -1) (*lenght)++;
}

bool Element (int n, int arr[]) {
    int lenght; Cardinality(arr, &lenght);
    for (int i = 0; i < lenght; ++i) if (arr[i] == n) return true;
    return false;
}

void Sort (int arr[]) {
    int lenght; Cardinality(arr, &lenght);
    bool flag;
    do {
        flag = false;
        for (int i = 0; i < lenght - 1; ++i) {
            if (arr[i] > arr[i + 1]) { std::swap(arr[i], arr[i + 1]); flag = true; }
        }
    } while (flag);
}

void Add (int n, int arr[]) {
    int lenght; Cardinality(arr, &lenght);
    if (isUniwersum(n) && !Element(n, arr)) { arr[lenght] = n; arr[lenght + 1] = -1; }
    Sort(arr);
}

void Add (int arr[], int n) {
    int lenght; Cardinality(arr, &lenght);
    if (isUniwersum(n) && !Element(n, arr)) { arr[lenght] = n; arr[lenght + 1] = -1; }
}

void Create (int n, int sourceArr[], int outputArr[]) {
    *outputArr = -1;
    for (int i = 0; i < n; ++i) if (isUniwersum(sourceArr[i])) Add(outputArr, sourceArr[i]);
    Sort(outputArr);
}

void Complement (int arr[], int outputArr[]) {
    *outputArr = -1;
    for (int i = 0; i < 4096; ++i) {
        if (!Element(i, arr)) Add(outputArr, i);
    }
}

void Union (int firstArr[], int secondArr[], int outputArr[]) {
    int firstLenght, secondLenght;
    Cardinality(firstArr, &firstLenght); Cardinality(secondArr, &secondLenght);
    *outputArr = -1;
    
    for (int i = 0; i < firstLenght; ++i) Add(outputArr, firstArr[i]);
    for (int i = 0; i < secondLenght; ++i) {
        if (!Element(secondArr[i], firstArr)) Add(outputArr, secondArr[i]);
    }
    Sort(outputArr);
}

void Intersection (int firstArr[], int secondArr[], int outputArr[]) {
    int firstLenght, secondLenght;
    Cardinality(firstArr, &firstLenght); Cardinality(secondArr, &secondLenght);
    *outputArr = -1;
    
    for (int i = 0; i < firstLenght; ++i) {
        for (int j = 0; j < secondLenght; ++j) {
            if (firstArr[i] == secondArr[j]) Add(outputArr, firstArr[i]);
        }
    }
}

void Difference (int firstArr[], int secondArr[], int outputArr[]) {
    int firstLenght, secondLenght;
    Cardinality(firstArr, &firstLenght); Cardinality(secondArr, &secondLenght);
    *outputArr = -1;
    
    for (int i = 0; i < firstLenght; ++i) {
        if (!Element(firstArr[i], secondArr)) Add(outputArr, firstArr[i]);
    }
    Sort(outputArr);
}

void Symmetric (int firstArr[], int secondArr[], int outputArr[]) {
    int firstLenght, secondLenght;
    Cardinality(firstArr, &firstLenght); Cardinality(secondArr, &secondLenght);
    
    Difference(secondArr, firstArr, outputArr);
    for (int i = 0; i < firstLenght; ++i) {
        if (!Element(firstArr[i], secondArr)) Add(outputArr, firstArr[i]);
    }
    Sort(outputArr);
}

bool Subset (int subsetArr[], int supersetArr[]) {
    int subsetLenght, supersetLenght;
    Cardinality(subsetArr, &subsetLenght); Cardinality(supersetArr, &supersetLenght);
    if (subsetLenght > supersetLenght) return false;
    
    for (int i = 0; i < subsetLenght; ++i) {
        if(!Element(subsetArr[i], supersetArr)) return false;
    }
    return true;
}

bool Equal (int firstArr[], int secondArr[]) {
    if (!Subset(firstArr, secondArr) || !Subset(secondArr, firstArr)) return false;
    return true;
}

bool Nonempty (int arr[ ]) {
    int lenght; Cardinality(arr, &lenght);
    for (int i = 0; i < lenght; ++i) if (arr[i] != 0) return true;
    return false;
}

bool Empty (int arr[]) {
    if (*arr == -1) return true;
    return false;
}

double Arithmetic (int arr[]) {
    if (Empty(arr)) return 0;
    int lenght; Cardinality(arr, &lenght);
    double sum = 0;
    for (int i = 0; i < lenght; ++i) {
        sum += arr[i];
    }
    return sum / lenght;
}

double Harmonic (int arr[]) {
    if (Empty(arr)) return 1;
    int lenght; Cardinality(arr, &lenght);
    double sum = 0;
    for (int i = 0; i < lenght; ++i) sum += (1.0/(arr[i]));
    return lenght / sum;
}

void MinMax (int arr[], int *min, int &max) {
    if (Nonempty(arr)) {
        *min = arr[0]; max = arr[0];
        int lenght; Cardinality(arr, &lenght);
        for (int i = 0; i < lenght; ++i) {
            if (arr[i] > max) max = arr[i];
            if (arr[i] < *min) *min = arr[i];
        }
    }
}

void Properties (int arr[], char operation[], double&arithmetic, double*harmonic, int&min, int*max, int&lenght) {
    int i = 0;
    while (*(operation+i) != 0) {
        switch (*(operation+i)) {
            case 'a': arithmetic = Arithmetic(arr); break;
            case 'h': *harmonic = Harmonic(arr); break;
            case 'm': MinMax(arr, &min, *max); break;
            case 'c': Cardinality(arr, &lenght); break;
            default: break;
        }
    ++i;
    }
}
