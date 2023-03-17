#include "inWordСonverter.hpp"

string singleDigit(int number) {
    switch (number) {
        case 1: return "jeden";
        case 2: return "dwa";
        case 3: return "trzy";
        case 4: return "cztery";
        case 5: return "piec";
        case 6: return "szesc";
        case 7: return "siedem";
        case 8: return "osiem";
        case 9: return "dziewiec";
        default: return "";
    }
}

string twoDigit(int number) {
    if (number < 10) return singleDigit(number);
    
    if (number == 10) return "dziesiec";
    if (number == 11) return "jedenascie";
    if (number == 12) return "dwanasicie";
    if (number == 13) return "trzynascie";
    if (number == 14) return "czternascie";
    if (number == 15) return "pietnascie";
    if (number == 16) return "szesnascie";
    if (number == 17) return "siedemnascie";
    if (number == 18) return "osiemnascie";
    if (number == 19) return "dziewietnascie";
    
    string rest = singleDigit(number%10);
    string prefix = singleDigit(number/10);
    
    if (number >= 20 && number < 30) return prefix + "dziescia" + " "+rest;
    if (number >= 30 && number < 50) return prefix + "dziesci" + " " +rest;
    if (number >= 50) return prefix + "dziesiat" + " " +rest;
    return "";
}

string threeDigit(int number) {
    if (number < 100) return twoDigit(number);
    
    string rest = twoDigit(number%100);
    string prefix = singleDigit(number/100);
    
    if (number >= 100 && number < 200) return "sto " + rest;
    if (number >= 200 && number < 300) return "dwiesci " + rest;
    if (number >= 300 && number < 500) return prefix + "sta " + rest;
    if (number >= 500) return prefix + "set " + rest;
    return "";
}

string fourDigit(int number) {
    if (number < 1000) return threeDigit(number);
    
    string rest = threeDigit(number%1000);
    string prefix = singleDigit(number/1000);
    
    if (number >= 1000 && number < 2000) return "tysiac "+rest;
    if (number >= 2000 && number < 4000) return prefix + " tysiace " + rest;
    if (number >= 4000) return prefix + " tysiecy " + rest;
    return "";
}
