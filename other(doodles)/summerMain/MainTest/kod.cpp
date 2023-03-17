// Denys Kyrychenko
#include <string>
using namespace std;

string p (string input, string operation, int firstSymbol) {
    string output;
    int n = operation[2] - 48;
    
    for (int i = 0; i < input.size() + n; ++i) {
        if (i < firstSymbol) output += input[i];
        else if (i >= firstSymbol + n) output += input[i - n];
        else { output += operation[4]; }
    }
    return output;
}

string u (string input, string operation, int firstSymbol) {
    string output;
    int n = operation[2] - 48;
    
    for (int i = 0; i < input.size(); ++i) {
        if (i < firstSymbol) output += input[i];
        else if (i >= firstSymbol + n) output += input[i];
    }
    return output;
}

string U (string input, string operation, int firstSymbol) {
    string output;
    int n = operation[2] - 48;
    
    for (int i = 0; i < input.size(); ++i) {
        if (i < firstSymbol - n) output += input[i];
        else if (i >= firstSymbol) output += input[i];
    }
    return output;
}

string w (string input, string operation, int firstSymbol, string paste) {
    string output;
    
    for (int i = 0; i < input.size() + paste.size(); ++i) {
        if (i < firstSymbol) output += input[i];
        else if (i >= firstSymbol + paste.size()) output += input[i - paste.size()];
        else output += paste[i - firstSymbol];
    }
    return output;
}

string W (string input, string operation, int firstSymbol, string paste, int m) {
    string output;
    if (paste.size() < m) paste.resize(m, ' ');
    if (paste.size() > m) paste.resize(m);
    
    return w(input, operation, firstSymbol, paste);
}

void prepareOperation (string &input, string &operation, int &firstSymbol) {
    string preparedInput;
    
    bool flag = 1;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '{' && flag) {
            firstSymbol = i;
            for (++i; input[i] != '}'; ++i) operation += input[i];
            flag = 0;
        }
        else preparedInput += input[i];
    }
    input = preparedInput;
}

string FormatujNapis (string input, string fOther, string sOther, string tOther) {
    string output = input;
    
    for (int i = 0; i < output.size(); ++i) {
        if (output[i] == '{') {
            string operation; int firstSymbol = 0;
            prepareOperation(output, operation, firstSymbol);
            
            switch (operation[0]) {
                case 'p':
                    output = p(output, operation, firstSymbol);
                    break;
                case 'u':
                    output = u(output, operation, firstSymbol);
                    break;
                case 'U':
                    output = U(output, operation, firstSymbol);
                    i -= (operation[2] - 47);
                    break;
                case 'w':
                    if (operation[2] - 48 == 1) output = w(output, operation, firstSymbol, fOther);
                    else if (operation[2] - 48 == 2) output = w(output, operation, firstSymbol, sOther);
                    else if (operation[2] - 48 == 3) output = w(output, operation, firstSymbol, tOther);
                    break;
                case 'W':
                    if (operation[2] - 48 == 1) output = W(output, operation, firstSymbol, fOther, operation[4] - 48);
                    else if (operation[2] - 48 == 2) output = W(output, operation, firstSymbol, sOther, operation[4] - 48);
                    else if (operation[2] - 48 == 3) output = W(output, operation, firstSymbol, tOther, operation[4] - 48);
                    break;
                default:
                    break;
            }
        }
        
    }
    return output;
}

string UsunSlowo (string input, int argument) {
    string output; int wordCount = 1;
    
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == ' ') { ++wordCount; output += ' '; ++i; }
        if (wordCount != argument) output += input[i];
    }
    
    return output;
}

string NajwiekszeSlowo (string input) {
    string output;
    int j;
    for (j = 0; j < input.size() && input[j] != ' '; ++j) output += input[j];
    
    for (int i = j; i < input.size(); ++i) {
        string temp;
        if (input[i] == ' ') {
            ++i;
            while (input[i] != ' ' && i < input.size()) temp += input[i++];
            --i;
            
            if (output < temp) output = temp;
        }
    }
    return output;
}

string NormalizujNapis (string input) {
    string output;
    
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == ' ' && (input[i + 1] == ' ' || input[i + 1] == '.' || input[i + 1] == ',')) continue;
        else if (input[i] == '.' || input[i] == ',') {
            output += input[i]; output += ' ';
        }
        else output += input[i];
    }
    return output;
}
