#include <iostream>
#include <cstring>
#define maxn 200005
using namespace std;
int n, q;
string s1[maxn], s2[maxn];
string t1, t2;
void solve();
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	while (q--)
		solve();
	return 0;
}
void solve() {
	cin >> t1 >> t2;
	if (t1.length() != t2.length()) {
		cout << "0\n";
		return;
	}
	int ans = 0;
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < (int)t1.length(); i++) {
			if (t1.substr(i, s1[k].length()) == s1[k]) {
				string t1_new = t1.substr(0, i) + s2[k] + t1.substr(i + s1[k].length(), t1.length() - i - s1[k].length() + 1);
				if (t1_new == t2) ans++;
			}
		}
	}
	cout << ans << endl;
}