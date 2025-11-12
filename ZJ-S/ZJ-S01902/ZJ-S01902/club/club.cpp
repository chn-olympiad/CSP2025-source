#include<bits/stdc++.h>
using namespace std;
int rd() {
    int x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x;
}
using ll = long long;
const int N = 1e5 + 10;
int T, n, a[N], d[N][3];
vector<int> del[3];
void solve() {
    n = rd();
    ll sum = 0;
    for (int i = 0; i < 3; i++) del[i].clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) d[i][j] = rd();
        int mx = max(max(d[i][0], d[i][1]), d[i][2]), mxp = 0;
        for (int j = 0; j < 3; j++) if (mx == d[i][j]) mxp = j;
        int dt = -1e9;
        for (int j = 0; j < 3; j++) if (j != mxp) dt = max(dt, -mx + d[i][j]);
        sum += mx;
        del[mxp].emplace_back(dt);
    }
    for (int i = 0; i < 3; i++) {
        sort(del[i].begin(), del[i].end());
        while ((int) del[i].size() > n / 2) {
            sum += del[i].back();
            del[i].pop_back();
        }
    }
    cout << sum << endl;

} 
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    T = rd();
    while (T--) solve();
    return 0;
}