#include <iostream>

using namespace std;

void isOperator(string input){
    int count = 0;
    for(int i = 0; i < input.length(); i++){
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '='){
            count++;
            cout << "Operator" << count << ": " << input[i] << endl;
        }
        i++;
    }
    if (count == 0){
        cout << "No operators found." << endl;
    }
}
int main()
{
    string input;
    cout << "Input:";
    cin >> input;
    isOperator(input);
    return 0;
}
