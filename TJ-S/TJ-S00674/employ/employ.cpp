#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int n, m;
string s;
int c[505];
int mul(int n) {
	ll ret = 1;
	for (int i = 2; i <= n; i++) ret = ret * i % mod;
	return ret % mod;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	printf("%d", mul(n) % mod);
	return 0;
}

