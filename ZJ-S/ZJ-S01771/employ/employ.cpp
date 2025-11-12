#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N][2];
int sum[N], a[N], p[N];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + (s[i] == '0');
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = i;
    int ans = 0;
    do {
        int tot = 0, fai = 0;
        for (int i = 1; i <= n; i++) {
            //cout << p[i] << " ";
            if(s[i] == '0') fai++;
            else if(a[p[i]] <= fai) fai++;
            else tot++;
        }
        if(tot >= m) ans++;
        //cout << endl;
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
}
/*

g++ -std=c++14 -O2 -Wall -Wextra -Wl,--stack=512000000 1.cpp -o 1
*/