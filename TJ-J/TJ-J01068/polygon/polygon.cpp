#define file_io(id) do { \
    freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 5100;
constexpr int MOD = 998244353;

int n, a[MAXN];
long long ans = 1;

int main() {
    file_io("polygon");
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        ans = (ans * 2) % MOD;
    ans -= n + (n * (n - 1)) / 2;

    cout << ans << endl;

	return 0;
}

