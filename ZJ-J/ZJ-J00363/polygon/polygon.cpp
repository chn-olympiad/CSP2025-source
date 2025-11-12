#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 10;
const int MOD = 998244353;
int a[MAXN], n, ans = 0;
bool vis[MAXN];
bool isPolygon(vector<int> &st) {
	if (st.size() < 3) return false;
	else {	
		int maxx = st[0], sumx = st[0];
		for (int i = 0; i < st.size(); i++) {
			maxx = max(maxx, st[i]);
			sumx += st[i];
		}
		return maxx > (2 * sumx);
	}
}
void out(vector<int> &dest) {
	for (int i = 0; i < dest.size(); i++) {
		cout << dest[i] << " ";
	}
	cout << endl;
}
void f(int scnt, int pos) {
	if (scnt >= 3 && scnt <= n) {
		vector<int> temp;
		for (int i = 1; i <= pos; i++) {
			if (!vis[i]) {
				temp.push_back(a[i]);
			}
		}
		if (temp.size() >= 3) 
		if (isPolygon(temp)) {
			ans++;
		}
		f(scnt + 1, pos + 1);
		f(scnt + 1, pos + 2);
	} else {
		f(scnt + 1, pos + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f(0, 0);
	cout << ans << endl;
	return 0;
}
// WA All