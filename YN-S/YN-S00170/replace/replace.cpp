#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, q;
string s[N][2];

int main(void) {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (t1.find(s[i][0]) != t1.npos) {
				string t3 = t1;
				int f = t1.find(s[i][0]);
				t3.erase(f, s[i][0].size());
				t3.insert(f, s[i][1]);
				cnt += (t3 == t2);
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}