#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000006];
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
			a[++cnt] = s[i] - '0';
		}
    }
    sort(a + 1, a + cnt + 1);
    for(int i = cnt; i > 0; i--){
        cout << a[i];
    }
    return 0;
}
