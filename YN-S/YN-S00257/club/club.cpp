#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int vis[N];
int T;

struct node {
	int a, b, c, val, id;
	bool operator<(node x) {
		if (a != x.a)
			return a > x.a;
		else if (b != x.b)
			return b > x.b;
		else
			return c > x.c;
	}
} e[N];
node s[N];

bool f(node x, node y) {
	return x.val > y.val;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(e, 0, sizeof(e));
		int n;
		cin >> n;
		int b = n / 2, sum = 0;
		for (int i = 1; i <= n; i++)
			cin >> e[i].a >> e[i].b >> e[i].c;
		sort(e + 1, e + n + 1);
		memset(s, 0, sizeof(s));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			s[1].val = e[i].a, s[1].id = 1;
			s[2].val = e[i].b, s[2].id = 2;
			s[3].val = e[i].c, s[3].id = 3;
			sort(s + 1, s + 4, f);
			if (vis[s[1].id] < b) {
				sum += s[1].val;
				vis[s[1].id]++;
			} else {
				int t = 1;
				while (1) {
					t++;
					if (vis[s[t].id] < b)
						break;
				}
				sum += s[t].val;
				vis[s[t].id]++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}