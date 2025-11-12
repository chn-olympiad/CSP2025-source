#include <bits/stdc++.h>
using namespace std;
int n[1111111], num;
string s;
char x;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        x = s[i];
        if (!(s[i] >= 'a' && s[i] <= 'z')){
            n[++num] = s[i] - '0';
        }
    }
    sort(n + 1, n + num + 1);
    for (int i = num; i > 0; i--){
        cout << n[i];
    }
    return 0;
}


