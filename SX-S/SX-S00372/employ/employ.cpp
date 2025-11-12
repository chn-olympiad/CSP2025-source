#include <iostream>
using namespace std;
const int N = 5e3+5, mod = 998244353;
int n, m, a[N];
long long res = 1;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		res *= i, res %= mod;
	cout << res;
	return 0;
}
