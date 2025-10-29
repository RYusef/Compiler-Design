#include <iostream>

using namespace std;

bool firstAlphabetic(string input){
    int i = 0;
    if (input[i] >= 'A' && input[i] <= 'Z' ||
        input[i] >= 'a' && input[i] <= 'z' ||
        input[i] == '_'){
            return true;
    }
    return false;
}

bool isIdentifier(string input){
    if(firstAlphabetic(input)){
        for(int i = 0; i < input.length(); i++){
        if (input[i] >= 'A' && input[i] <= 'Z' ||
            input[i] >= 'a' && input[i] <= 'z' ||
            input[i] >= '0' && input[i] <= '9'
            input[i] == '_'){
                return true;
        }
        i++;
    }
    return true;
    }
}
int main()
{
    string input;
    cout << "Check if Identifier or Not" << endl;
    cout << "Input:";
    cin >> input;
    if (isIdentifier(input)){
        cout << "Identifier" << endl;
    }
    else{
        cout << "Non identifier" << endl;
    }
    return 0;
}


