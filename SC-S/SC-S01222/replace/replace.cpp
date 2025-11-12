#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q;
string ori[MAXN], rep[MAXN];
string depa[MAXN], dest[MAXN];
map<pair<string, string>, int> keys;

inline pair<string, string> dif(string &a, string &b) {
	int len = a.length();
	int l = 0, r = a.length() - 1;
	while (l < len && a[l] == b[l])
		++l;
	while (r > 0 && a[r] == b[r])
		--r;
	if (l > r)
		return make_pair("", "");
	return make_pair(a.substr(l, r - l + 1), b.substr(l, r - l + 1));
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> ori[i] >> rep[i];
	}
	for (int i = 1; i <= q; ++i) {
		cin >> depa[i] >> dest[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		auto ret = dif(ori[i], rep[i]);
		keys[ret]++;
	}
	
	for (int i = 1; i <= q; ++i) {
		auto ret = dif(depa[i], dest[i]);
		if (keys.find(ret) != keys.end())
			cout << keys[ret] << '\n';
		else
			cout << "0\n";
	}
	return 0;
}