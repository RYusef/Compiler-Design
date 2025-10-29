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
            input[i] >= '0' && input[i] <= '9' ||
            input[i] == '_'){
                return true;
        }
        i++;
    }
    return true;
    }
}

//Need Number input
double findAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (double)sum / n;
}

int findMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < minVal)
            minVal = arr[i];
    return minVal;
}

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

string getFullName(string first, string last) {
    return first + " " + last;
}

int main()
{
    string firstName, lastName;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Full name = " << getFullName(firstName, lastName) << endl;


    cout << "Choose what to check: " <<endl;
    cout << "1.Numeric, 2.Operator, 3.Comment, 4.Identifier, 5. Average, 6. Minimum, 7. Maximum" <<endl;

    int k;
    cin >> k;
    if (k < 5){
        string input;
        cout << "Input:";
        //cin >> input;
        cin.ignore();
        getline(cin, input);
        switch (k){
            case 1:
                cout << "Check if Numeric or Not" << endl;
                if (isNumeric(input)){
                    cout << "Numeric Constant" << endl;
                }
                else{
                    cout << "Non numeric" << endl;
                }
                break;
            case 2:
                cout << "Check if Operator or Not" << endl;
                isOperator(input);
                break;
            case 3:
                cout << "Check if Comment or Not" << endl;
                isComment(input);
                break;
            case 4:
                cout << "Check if Identifier or Not" << endl;
                if (isIdentifier(input)){
                    cout << "Identifier" << endl;
                }
                else{
                    cout << "Non identifier" << endl;
                }
                break;
        }
    }

    else{
        int n;
                cout << "Enter number of elements: ";
                cin >> n;

                int arr[n];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++){
                    cin >> arr[i];
                }
        switch (k){
            case 5:
                cout << "Average value = " << findAverage(arr, n) << endl;
                break;
            case 6:
                cout << "Minimum value = " << findMin(arr, n) << endl;
                break;
            case 7:
                cout << "Maximum value = " << findMax(arr, n) << endl;
                break;
        }
    }
    return 0;
}

