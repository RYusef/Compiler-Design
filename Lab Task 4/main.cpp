#include <bits/stdc++.h>
using namespace std;

string keywords[] = {
    "int","float","double","char","void","if","else",
    "for","while","return","break","continue","long",
    "short","switch","case","default","class","struct",
    "string","bool","true","false","do","include","namespace","using"
};
int keywordCount = 27;

bool isKeyword(string s){
    for(int i=0; i<keywordCount; i++){
        if(s == keywords[i])
            return true;
    }
    return false;
}

bool isIdentifier(string s){
    if(s.length() == 0) return false;

    if(!( (s[0]>='A' && s[0]<='Z') ||
          (s[0]>='a' && s[0]<='z') ||
           s[0]=='_')) return false;

    for(int i=1; i<s.length(); i++){
        char c = s[i];
        if(!((c>='A'&&c<='Z') || (c>='a'&&c<='z') ||
             (c>='0'&&c<='9') || c=='_'))
            return false;
    }
    return true;
}

bool isNumber(string s){
    int dotCount = 0;
    if(s.length() == 0) return false;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '.'){
            dotCount++;
            if(dotCount > 1) return false;
        }
        else if(!(s[i]>='0' && s[i]<='9')){
            return false;
        }
    }
    return true;
}

bool isStringConstant(string s){
    return (s.length() >= 2 && s[0]=='"' && s[s.length()-1]=='"');
}

string operatorsList[] = {
    "+","-","*","/","%","=","==","!=",">","<",
    ">=","<=","++","--","&&","||","!","+=",
    "-=","*=","/=","%="
};
int operatorCount = 23;

bool isOperator(string s){
    for(int i=0; i<operatorCount; i++){
        if(s == operatorsList[i])
            return true;
    }
    return false;
}

char punctuation[] = {'(',')','{','}','[',']',';',',','.','<','>'};
int punctCount = 11;

bool isPunctuation(string s){
    return (s.length() == 1 &&
            ( strchr(punctuation, s[0]) != NULL ));
}

// ---------------------- MAIN ----------------------
int main()
{
    ifstream f("sample.txt");
    if(!f.is_open()){
        cout << "File not found!";
        return 0;
    }

    string line, token;

    while(getline(f, line))
    {
        cout << "Line: " << line << endl;

        string current = "";

        // Manual character-by-character tokenization
        for(int i=0; i<=line.length(); i++)
        {
            char ch = line[i];

            if(ch==' ' || ch=='\t' || ch=='\0')
            {
                if(current != ""){
                    token = current;
                    cout << "  \"" << token << "\" -> ";

                    if(isKeyword(token)) cout << "Keyword";
                    else if(isIdentifier(token)) cout << "Identifier";
                    else if(isNumber(token)) cout << "Number";
                    else if(isStringConstant(token)) cout << "String Constant";
                    else if(isOperator(token)) cout << "Operator";
                    else if(isPunctuation(token)) cout << "Punctuation";
                    else cout << "Unknown";

                    cout << endl;
                    current = "";
                }
            }
            else
            {
                current += ch;
            }
        }

        cout << endl;
    }

    return 0;
}
