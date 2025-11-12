#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    getline(cin, s);
    int s1 = s.size();
    if(s.size() == 1){
        cout << s << endl;
        return 0;
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '9'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '8'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '7'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '6'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '5'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '4'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '3'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '2'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '1'){
            cout << c;
        }
    }
    for(int i = 0; i < s1; i++){
        char c = s[i];
        if(c == '0'){
            cout << c;
        }
    }
    return 0;
}
