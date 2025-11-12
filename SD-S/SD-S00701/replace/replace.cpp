#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+5, L = 5e6+5;
int n, q;
string fs1, fs2;
ll ans;
string s1[N], s2[N];

bool check(string s, string r) {
	for (int i=0;i<s.size();i++) {
		if (s[i] != r[i]) return 0;
	}
	return 1;
}

void search(int j) {
	string s, t;
	for (int i=0;i<fs1.size();i++) {
		for (int k=0;k<s1[j].size();k++) {
			if (fs1[i] != s1[j][k]) {
				s = "";
				break;
			}
			s += s2[j][k];
			if (k == s1[j].size()-1) {
				string t;
				for (int tf=0;tf<fs1.size();tf++) {
					if (i <= tf && tf <= k) t += s2[j][tf];
					else t += fs1[tf];
				}
				cout << check(t, fs2);
				if (check(t, fs2)) ans++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i=1;i<=q;i++) {
		cin >> fs1 >> fs2;
		if (fs1.size() != fs2.size()) {
			cout << 0 << '\n';
		}
		for (int j=1;j<=n;j++) {
			search(j);
		}
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}
