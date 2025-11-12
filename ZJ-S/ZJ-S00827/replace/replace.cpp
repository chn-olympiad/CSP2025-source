#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define inf 1e9
using ll = long long;
using db = double;
using namespace std;
constexpr int N = 3e3 + 5, M = 1e6 + 5, P = 13331;
int n, q;
string a[N], b[N];
unsigned long long h1[N][N], h2[N][N], h3[N], h4[N], s[N];
bool ifeq(int i, int l, int r) {
	return h1[i][a[i].size()] == h3[r] - h3[l - 1] * s[r - l + 1];
}
bool ifeq2(int i, int l, int r) {
	return h2[i][b[i].size()] == h4[r] - h4[l - 1] * s[r - l + 1];
}
bool ifeq3(int l, int r) {
	return h3[r] - h3[l - 1] * s[r - l + 1] == h4[r] - h4[l - 1] * s[r - l + 1];
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	s[0] = 1;
	for (int i = 1; i < N; ++ i) s[i] = s[i - 1] * P;
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i] >> b[i];
		for (int j = 1; j <= a[i].size(); ++ j) {
			h1[i][j] = h1[i][j - 1] * P + a[i][j - 1] - 'a';
		}
		for (int j = 1; j <= b[i].size(); ++ j) {
			h2[i][j] = h2[i][j - 1] * P + b[i][j - 1] - 'a';
		}
	}
	while (q --) {
		int ans = 0;
		cin >> a[0] >> b[0];
		for (int i = 1; i <= a[0].size(); ++ i) {
			h3[i] = h3[i - 1] * P + a[0][i - 1] - 'a';
		}
		for (int i = 1; i <= b[0].size(); ++ i) {
			h4[i] = h4[i - 1] * P + b[0][i - 1] - 'a';
		}
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j + a[i].size() - 1 <= a[0].size(); ++ j) {
				if (ifeq(i, j, j + a[i].size() - 1) && ifeq2(i, j, j + a[i].size() - 1) &&
				(j == 1 || ifeq3(1, j - 1)) && (j + a[i].size() - 1 == a[0].size() ||
				ifeq3(j + a[i].size(), a[0].size()))) ++ ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}