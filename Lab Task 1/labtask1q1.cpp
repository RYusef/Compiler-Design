#include <iostream>

using namespace std;

bool isNumeric(string input){
    for(int i = 0; i < input.length(); i++){
        if (input[i] < '0' || input[i] > '9'){
            return false;
        }
        i++;
    }
    return true;
}
int main()
{
    string input;
    cout << "Input:";
    cin >> input;
    if (isNumeric(input)){
        cout << "Numeric Constant" << endl;
    }
    else{
        cout << "Non numeric" << endl;
    }
    return 0;
}

