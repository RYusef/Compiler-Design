#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    int state = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (state == 0) {
            if (c == 'b')
                state = 0;
            else if (c == 'a')
                state = 1;
            else {
                state = -1;
                break;
            }
        }

        else if (state == 1) {
            if (c == 'a')
                state = 1;
            else if (c == 'b')
                state = 2;
            else {
                state = -1;
                break;
            }
        }

        else if (state == 2) {
            if (c == 'a')
                state = 3;
            else {
                state = -1;
                break;
            }
        }

        else if (state == 3) {
            if (c == 'a' || c == 'b')
                state = 1;
            else {
                state = -1;
                break;
            }
        }
    }

    if (state == 1)
        cout << "String ACCEPTED\n";
    else
        cout << "String REJECTED\n";

    return 0;
}
