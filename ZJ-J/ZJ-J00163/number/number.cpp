#include <bits/stdc++.h>
using namespace std;
string s;
char c[1000010];
long long cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(char ch:s){
        if('0'<=ch && ch<='9'){
            c[++cnt] = ch;
        }
    }
    sort(c + 1, c + 1 + cnt);
    if(c[cnt]=='0' || cnt==0){
        cout << 0 << '\n';
    }else{
        for (int i = cnt; i >= 1;i--){
            cout << c[i];
        }
        cout << '\n';
    }
    return 0;
}
/*
AK 自动机   rp++
CCF Orz
*/