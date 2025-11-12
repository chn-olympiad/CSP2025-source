#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

struct Node {
	int one, two, three, pos;
} a[N];

struct Nd {
	int s[4], maxx;
} f[N][4];

int T, n, ans;
int c[N][4], num[N];

bool cmp(Node A, Node B) {
	if(A.one != B.one) return A.one > B.one;
	else return A.pos < B.pos;
}

void DFS(int x) {
	if(x > n) {
		int c1 = 0, c2 = 0, c3 = 0, sum = 0;
		for(int i = 1; i <= n; i++) {
			if(num[i] == 1) c1++, sum += c[i][1];
			if(num[i] == 2) c2++, sum += c[i][2];
			if(num[i] == 3) c3++, sum += c[i][3];
		}
		if(c1 > n / 2 || c2 > n / 2 || c3 > n / 2) return;
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= 3; i++)
		if(!num[x]) num[x] = i, DFS(x + 1), num[x] = 0;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				for(int k = 1; k <= 3; k++) f[i][j].maxx = 0, f[i][j].s[k] = 0;
			}
		}
		memset(c, 0, sizeof c);
		for(int i = 1; i <= n; i++) cin >> a[i].one >> a[i].two >> a[i].three, a[i].pos = i, c[i][1] = a[i].one, c[i][2] = a[i].two, c[i][3] = a[i].three;
		int flag = 1;
		for(int i = 1; i <= n; i++)
			if(a[i].two != 0 || a[i].three != 0) flag = 0;
		if(flag) {
			sort(a + 1, a + n + 1, cmp);
			int ans = 0;
			for(int i = 1; i <= n / 2; i++) ans += a[i].one;
			cout << ans << '\n';
			continue;
		}
		if(n <= 16) {
			memset(num, 0, sizeof num);
			ans = 0;
			DFS(1);
			cout << ans << '\n';
		}
		if(n > 16) {
			for(int i = 1; i <= n; i++) 
				for(int j = 1; j <= 3; j++) f[i][j].maxx = c[i][j], f[i][j].s[j] = 1;
			for(int i = 2; i <= n; i++) {
				for(int j = 1; j <= 3; j++) {
					for(int k = 1; k <= 3; k++) {
						if(f[i - 1][k].s[j] + 1 > n / 2) continue;
						if(f[i][j].maxx < f[i - 1][k].maxx + c[i][j]) {
							f[i][j].maxx = f[i - 1][k].maxx + c[i][j];
							for(int p = 1; p <= 3; p++) {
								if(p == j) f[i][j].s[p] = f[i - 1][k].s[p] + 1;
								else f[i][j].s[p] = f[i - 1][k].s[p];
							}
						}
					}
				}
			}
			cout << max(f[n][1].maxx, max(f[n][2].maxx, f[n][3].maxx)) << '\n';
		}
	}
	return 0;
}
