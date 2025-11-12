#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

int n, m, a[N], f[N];
unordered_map<int, int> idx;

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    idx[0]=0;
    for(int i=1, v=0; i<=n; ++i) {
        v^=a[i], f[i]=f[i-1];
        int w=v^m;
        if(idx[w] || !w) f[i]=max(f[i], f[idx[w]]+1);
        idx[v]=i;
    }
    cout << f[n] << '\n';
    return 0;
}