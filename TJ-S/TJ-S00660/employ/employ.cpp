#define file_io(id) do { \
	freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <iostream>
using namespace std;
constexpr int MOD = 998244353;
int n, m;
int main() {
	file_io("employ");
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	long long ans = 1;
	for (int i = 1; i <= n; i++)
        ans = (ans * i) % MOD;
    cout << ans << endl;
	return 0;
}
