#include <iostream>

using namespace std;
void print(int i, string input){
    while (i < input.length()){
        cout << input[i];
        i++;
    }
}

void isComment(string input){
    int count = 0;
    for(int i = 0; i < input.length(); i++){
        if (input[i] == '/' && input[i + 1] == '/'){
            cout << "Single Comment" << endl;
            count++;
            print(i , input);
            break;
        }
        else if (input[i] == '/' && input[i + 1] == '*'){
            for (int j = i; j < input.length(); j++){
                if (input[j] == '*' && input [j + 1] == '/'){
                    cout << "Multiple Line Comment" << endl;
                    count++;
                    print(i, input);
                    break;
                }
            }
        }
        i++;
    }
    if (count == 0){
        cout << "No comment" << endl;
    }
}

int main()
{
    string input;
    cout << "Input:";
    getline(cin, input);
    isComment(input);
    return 0;
}


