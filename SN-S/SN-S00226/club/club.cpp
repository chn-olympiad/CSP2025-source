// 张思晨-SN-S00226-西安滨河学校 
#include <bits/stdc++.h>

#define int long long
using namespace std;

int T;
const int N = 1e5 + 1000;
int n;
int a[N][4];
bool d[4];
int ans = 0;
int ret[4];

struct edge {
	int val;
	int per;
	int sub;
}Edge[N * 3];
int cnt = 0;
bool cmp(edge a, edge b) {
	return a.val > b.val;
}
int mn, mx;
int k1, k2;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while (T--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(Edge, 0, sizeof(Edge));
		d[1] = d[2] = d[3] = 0;
		ans = 0;
		cnt = 0;
		ret[1] = ret[2] = ret[3] = n / 2;
		
		
		for (int i = 1; i <= n; ++i) {
			mn = 1e9;
			mx = 0;
			for (int j = 1; j <= 3; ++j) {
				cin >> a[i][j];
				if (a[i][j] < mn) {
					mn = a[i][j];
					k1 = j;
				}
				if (a[i][j] > mx) {
					mx = a[i][j];
					k2 = j;
				}
				if (a[i][j])
					d[j] = 1;
			}
			
			int k = 6 - k1 - k2;
			int o = a[i][k];
			a[i][1] -= o;
			a[i][2] -= o;
			a[i][3] -= o;
			ans += o;
			
			for (int j = 1; j <= 3; ++j) {
				Edge[cnt].val = a[i][j];
				Edge[cnt].sub = j;
				Edge[cnt++].per = i;
			}
		}
		
		sort(Edge, Edge + cnt, cmp);
		for (int i = 0; i != cnt; ++i) {
			if (a[Edge[i].per][0] == 0 && ret[Edge[i].sub]) {
				a[Edge[i].per][0] = 1;
				ret[Edge[i].sub]--;
				ans += Edge[i].val;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

