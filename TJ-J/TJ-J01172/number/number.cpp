#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    string num;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){
            num += s[i];
        }
    }
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    cout << num;

    return 0;
}

