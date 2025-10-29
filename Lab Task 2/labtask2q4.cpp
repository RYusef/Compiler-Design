#include <iostream>
#include <string>
using namespace std;

string getFullName(string first, string last) {
    return first + " " + last;
}

int main() {
    string firstName, lastName;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Full name = " << getFullName(firstName, lastName) << endl;

    return 0;
}
