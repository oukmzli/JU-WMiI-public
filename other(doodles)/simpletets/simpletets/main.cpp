#include <iostream>

const size_t max_len = 256;

int main()
{
    using namespace std;

    cout << "Please enter string: ";
    char* str = new char[max_len + 1];
    for (size_t i = 0; i != max_len; ++i)
    {
        cin >> str[i];
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }

    cout << "Entered string is:" << str << endl;
    delete [] str;

    return 0;
}
