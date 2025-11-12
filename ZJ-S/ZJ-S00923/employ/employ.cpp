#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second
typedef pair<int, int> PP;
typedef double db;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, m, c[N], pos[N];
string a;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    // freopen("employ/employ2.in", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> a; a = " " + a;
    // cout << a << endl;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i], pos[i] = i;
    }
    int ans = 0;
    do {
        int cnt = 0;
        for(int i = 1; i <= n; i ++) {
            // cout << pos[i] << ' ';
            if(a[i] == '0' || cnt >= c[pos[i]]) cnt ++;
        }
        // cout << cnt << endl;
        if(n - cnt >= m) ans ++;
    }while(next_permutation(pos + 1, pos + n + 1));
    cout << ans << endl;
    return 0;
}