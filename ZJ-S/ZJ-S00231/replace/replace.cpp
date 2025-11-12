#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int P = 131;
map<ULL, int> cnt;
int n, q;
string a, b;

ULL f() {
	int len = a.size();
	int l = 0, r = len - 1;
	while (l < len && a[l] == b[l]) l++;
	if (l == len) return -1;
	while (r >= l && a[r] == b[r]) r--;
	a = a.substr(l, r - l + 1), b = b.substr(l, r - l + 1);
	a = a + b;
	len = a.size();
	ULL res = 0;
	for (int i = 0; i < len; i++)
		res = res * P + a[i] - 'a' + 1;
	return res;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		ULL res = f();
		if (res != -1) cnt[res]++;
	}
	while (q--) {
		cin >> a >> b;
		if (a.size() != b.size()) {
			puts("0");
			continue;
		}
		ULL t = f();
		int res = (cnt.count(t) ? cnt[t] : 0);
		printf("%d\n", res);
	}
	return 0;
}
