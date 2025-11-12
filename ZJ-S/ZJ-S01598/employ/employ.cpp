#include <bits/stdc++.h>
using namespace std;
const int N = 1e4, M = 998244353;

int n,m;
int sum[N],per[N],idx=1;
string s;

int main(){
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++){
        if(s[i] == '1') sum[idx]++;
        else idx++;
    }
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        if(x < idx) per[x]++;
        else per[idx]++;
    }
    
    return 0;
}