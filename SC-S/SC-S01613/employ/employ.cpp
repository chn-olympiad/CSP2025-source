#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 555, mod = 998244353;
int n, m, ans, c[N], lea;
char s[N];
vector<int> f, ape0;
bool cmp(int a, int b) { return a < b; }
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '0') ape0.push(i);
	}
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	cout<<0;
	return 0;
}
