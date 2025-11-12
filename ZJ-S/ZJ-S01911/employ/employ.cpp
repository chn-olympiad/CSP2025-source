#include<bits/stdc++.h>
#define N 20
using namespace std;

int n, m, a[N];
string s;

int p[N];

bool check() {
    int cnt=0;
    for(int i=1; i<=n; ++i) {
        if(s[i]=='0' || cnt>=a[p[i]])
            ++cnt;
    }
    return n-cnt>=m;
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    s=' '+s;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    for(int i=1; i<=n; ++i)
        p[i]=i;
    int rsl=0;
    rsl+=check();
    while(next_permutation(p+1, p+n+1))
        rsl+=check();
    cout << rsl << '\n';
    return 0;
}