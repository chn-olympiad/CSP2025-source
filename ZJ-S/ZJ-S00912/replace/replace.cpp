// 沒有別的選擇了，我必須贏
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 201000;

int n, q;

void solveA() {
	string s1[N], s2[N];
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	string t1, t2;
	cin >> t1 >> t2;
	if (t1.length() != t2.length()) {
		printf("0\n");
		return;
	}
	vector<int> e[30];
	int l = t1.length();
	for (int i = 0; i < l; i++) {
		e[t1[i]].push_back(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (auto u : e[s1[i][0]]) {
			if (t2[u] != s2[i][0]) {
				continue;
			}
			for (int k = 1; k < s1[i].length(); k++) {
				if (u + k >= l) {
					ans--; break;
				}
				if (t2[u + k] != s2[i][k]) {
					ans--; break;
				}
				if (t1[u + k] != s1[i][k]) {
					ans--; break;
				}
			}
			ans++;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	if (q == 1) {
		solveA();
	}
}
