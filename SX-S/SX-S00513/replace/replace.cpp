#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5, M = 2e6+5;
int n, q;
string t1, t2;

struct T {
	string a, b;
	int x, y, l;
} s[N];
vector<int>h[M];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].b;
		s[i].x = s[i].a.find('b');
		s[i].y = s[i].b.find('b');
		s[i].l = s[i].b.size();
		h[abs(s[i].x - s[i].y)].push_back(i);
	}
	while (q--) {
		cin >> t1 >> t2;
		int x = t1.find('b');
		int y = t2.find('b');
		int cnt = 0, t = abs(x - y);
		for (int i = 0; i < h[t].size(); i++) {
			if ((s[h[t][i]].l - 1 - s[h[t][i]].x <= t1.size() - 1 - x ) && (s[h[t][i]].x <= x) ) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
