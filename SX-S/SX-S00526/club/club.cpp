#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		int u = ch - 48;
		x = (x << 1) + (x << 3) + u;
		ch = getchar();
	}
	return f * x;
}

inline void write(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n > 9)
		write(n / 10);
	char c = n % 10 + 48;
	putchar(c);
}
const int N = 1e5+10;
int a[N][5];

struct fp {
	int id, x, c;
};

bool cmp(fp aa, fp b) {
	return aa.c < b.c;
}
vector<fp> team[5];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	//int n;
	//cin >> n;
	//cout << n + 1;
	int t = read();
	while (t--) {
		int n = read();
		int ans = 0;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= 3; i++) {
			team[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			int mx = 0, mxid = 0;
			for (int j = 1; j <= 3; j++) {
				a[i][j] = read();
				if (mx < a[i][j]) {
					mx = a[i][j];
					mxid = j;
				}
			}
			int mse;
			if (mxid == 1)
				mse = max(a[i][2], a[i][3]), cnt1++;
			else if (mxid == 2)
				mse = max(a[i][1], a[i][3]), cnt2++;
			else
				mse = max(a[i][2], a[i][1]), cnt3++;
			ans += mx;
			fp u;
			u.id = i;
			u.x = mx;
			u.c = mx - mse;
			team[mxid].push_back(u);
		}
		for (int i = 1; i <= 3; i++) {
			sort(team[i].begin(), team[i].end(), cmp);
		}
		int j1 = 0, j2 = 0, j3 = 0;
		while (cnt1 > n / 2) {
			cnt1--;
			ans -= team[1][j1].c;
			j1++;
		}
		while (cnt2 > n / 2) {
			cnt2--;
			ans -= team[2][j2].c;
			j2++;
		}
		while (cnt3 > n / 2) {
			cnt3--;
			ans -= team[3][j3].c;
			j3++;
		}
		write(ans);
		cout << '\n';
	}
	return 0;
}
