#include <bits/stdc++.h>
//#define int long long
#define maxn 100010
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -f;ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch -'0'; ch = getchar();}
	return x * f;
}
int n;
int a[maxn][4];
struct node {
	int bigg, smal, c, mind, maxd;
	bool operator <(const node &a) const {
		return a.c < c;
	}
}d[maxn];
priority_queue <node> q[4];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) {
//			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a[i][1] = read(); a[i][2] = read(); a[i][3] = read();
		}
		for (int i = 1; i <= n; i++) {
			int minn = INT_MAX, maxx = INT_MIN;
			d[i].smal = a[i][1], d[i].mind = 1; minn = a[i][1];
			d[i].bigg = a[i][1], d[i].maxd = 1; maxx = a[i][1];
			for (int j = 2; j <= 3; j++) {//bug
				if (a[i][j] <= minn) {
					d[i].smal = a[i][j], d[i].mind = j;minn = a[i][j];
				}
				if (a[i][j] > maxx) {
					d[i].bigg = a[i][j], d[i].maxd = j;maxx = a[i][j];
				} 
			}
			d[i].mind = 6 - d[i].mind - d[i].maxd;
			d[i].smal = a[i][1] + a[i][2] + a[i][3] - d[i].smal - d[i].bigg; 
			d[i].c = d[i].bigg - d[i].smal;
		}
		int cnt[4]= {0, 0, 0, 0};
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int nowmax = d[i].maxd, nowmin = d[i].mind;
			
//			cerr << i << " " << nowmax << " " << nowmin << endl;
			if (cnt[nowmax] + 1 <= n / 2) {
				cnt[nowmax] ++;
				q[nowmax].push(d[i]);
				ans += d[i].bigg;
			}
			else {
//				cerr << "i:" << i << endl;
				node t = q[d[i].maxd].top();
				if (t.c < d[i].c) {//huan
//				cout << t.bigg << " " << t.smal << " " << d[i].bigg << endl;
					ans -= t.bigg; ans += t.smal; ans += d[i].bigg;
//					cerr << ans << endl;
					cnt[t.mind] ++;
					q[t.mind].push(t);
					q[nowmax].pop();
					q[nowmax].push(d[i]);
				}
				else {
					ans += d[i].smal;
					cnt[d[i].mind] ++;
					q[d[i].mind].push(d[i]);
				}
			}
		}
		cout << ans << endl;
		
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= n; j++) {
				a[j][i] = 0;
			}
			while(!q[i].empty()) q[i].pop();
		}
		memset(d, 0, sizeof(d));
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

