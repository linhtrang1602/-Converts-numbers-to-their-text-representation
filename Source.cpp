#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

// This program only works with the number has less than 10 digits
// This program do not work with decimal
// The text converted is in English

unsigned long long int n;
string theNumber;

// Get the the sign of the number
string sign(string theNumber)
{
    // Set the prefix to "negative" if the given number is a negative number
    if (theNumber[0] == '-') {
        return "negative ";
    }
    else {
        return "";
    }
}

// Remove redundant characters and get the positive part of the number
void getThePos(string theNumber)
{
    string thePos = "";

    for (unsigned int i = 0; i < theNumber.length(); i++)

    {
        // Take only digits
        if (theNumber[i] >= '0' && theNumber[i] <= '9') {
            thePos += theNumber[i];
        }
    }
    // The positive part of the number
    n = atoi(thePos.c_str());

}
//-------------------------------------------------------------------------------------
const string EMPTY = "";

const string one[] = { EMPTY, "one ", "two ", "three ", "four ", "five ",
                "six ", "seven ", "eight ", "nine ", "ten ", "eleven ",
                "twelve ", "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ", "nineteen " };

const string ten[] = { EMPTY, EMPTY, "twenty ", "thirty ", "forty ", "fifty ",
                "sixty ", "seventy ", "eighty ", "ninety " };

// Function to convert a single-digit or two-digit number into words
string convertToDigit(int m, string suffix)
{
    // if `n` is zero
    if (m == 0) {
        return EMPTY;
    }

    // split `n` if it is more than 19
    if (m > 19) {
        return ten[m / 10] + one[m % 10] + suffix;
    }
    else {
        return one[m] + suffix;
    }
}

// Function to convert a given number (max 9 digits) into words
string convert()
{
    // string to store word representation of the given number
    string res = "";

    // this handles digits at ones and tens place
    res += convertToDigit((n % 100), "");

    if (n > 100 && n % 100) {
        res = "and " + res;
    }

    // this handles digit at hundred place
    res = convertToDigit(((n / 100) % 10), "hundred ") + res;

    // this handles digits at thousand and tens thousand place
    res = convertToDigit(((n / 1000) % 100), "thousand ") + res;

    // this handles digits at hundred thousand and one million place
    res = convertToDigit(((n / 100000) % 100), "lakh, ") + res;

    // this handles digits at ten million and hundred million place
    res = convertToDigit((n / 10000000) % 100, "crore, ") + res;

    // this handles digits at ten million and hundred million place
    res = convertToDigit((n / 1000000000) % 100, "billion, ") + res;

    // return sign(theNumber) + res;
    string ans = sign(theNumber);
    ans += res;
    return ans;
}
//-----------------------------------------------------------------------------------
// Get the input
void input()
{
    getline(cin, theNumber);
}
// Print out the text
void output()
{
    if (n == 0)
    {
        cout << "zero";
    }
    else {
        cout << convert();
    }
}
//-----------------------------------------------------------------------------------
// C++ program to convert numbers to words
int main()
{
    input();
    getThePos(theNumber);
    output();
    return 0;
}