#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n, Q, d[N], l[N], r[N];
string s[N][2];
void sbf() {
	while (Q--) {
		string a, b; cin >> a >> b;
		if (a.size() != b.size()) {
			cout << "0\n"; continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i][0] == s[i][1]) continue;
			int ta = a.find(s[i][0]), tb = b.find(s[i][1]);
			if (ta == tb && b == a.substr(0, ta) + s[i][1] + a.substr(ta + s[i][1].size())) {
				++ans;
			}
		}
		cout << ans << '\n';
	}
}
void ssp() {
	for (int i = 1; i <= n; i++) {
		int ta = s[i][0].find('b'), tb = s[i][1].find('b');
		l[i] = ta, d[i] = ta - tb, r[i] = s[i][0].size() - 1 - l[i];
	}
	while (Q--) {
		string a, b; cin >> a >> b;
		if (a.size() != b.size()) {
			cout << "0\n"; continue;
		}
		int ta = a.find('b'), tb = b.find('b'), td = ta - tb, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (td == d[i] && ta >= l[i] && a.size() - 1 - ta >= r[i]) ++ans;
		}
		cout << ans << '\n';
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	if (Q == 1 || n <= 1000) sbf();
	else ssp();
	return 0;
}