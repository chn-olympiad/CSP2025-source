#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 5e2 + 8;
long long md = 998244353;
int n, m, c[maxn];
string s;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }


    long long ans = 1;
    for (long long i = 1; i <= n; i++) {
        (ans *= i) %= md;
    }
    cout << ans << '\n';

    return 0;
}
