#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 20;
const int INF = 0x7f7f7f7f;
const int mod = 998244353;
typedef long long ll;
ll f[N];
int n, m, c[N];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = f[i - 1] * i % mod;
	cout << f[n];
}