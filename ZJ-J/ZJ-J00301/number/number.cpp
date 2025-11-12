#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7;
const int M = 5005;
int a[15], cnt = 0; 
string s;
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            a[s[i] - '0']++;
            cnt++;
        }
    }
    string k;
    
    for(int i = 9; i >= 0; i--){
        while(a[i] != 0){
            a[i] -= 1;
            cout << i; 
        }
    }
    cout << endl;
    return 0;
}