#include <bits/stdc++.h>
using namespace std;
int t, n, sx, cnt[4], g[4][4], maxnl, gsx[4];
struct ssz {
	int num[4], xdmax;
} a[100005];
bool cmp1(ssz x, ssz y) {
	if (x.num[1] != y.num[1]) return x.num[1] > y.num[1];
	else if (x.num[2] != y.num[2]) return x.num[2] > y.num[2];
	else return x.num[3] > y.num[3];
}
bool cmp2(ssz x, ssz y) {
	if (x.num[2] != y.num[2]) return x.num[2] > y.num[2];
	else if (x.num[3] != y.num[3]) return x.num[3] > y.num[3];
	else return x.num[1] > y.num[1];
}
bool cmp3(ssz x, ssz y) {
	if (x.num[3] != y.num[3]) return x.num[3] > y.num[3];
	else if (x.num[2] != y.num[2]) return x.num[2] > y.num[2];
	else return x.num[1] > y.num[1];
}
int pzd(ssz a[100005], int numc) {
	g[numc][1]=g[numc][2]=g[numc][3]=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	if (numc == 1)
		sort(a + 1, a + 1 + n, cmp1);
	else if (numc == 2) sort(a + 1, a + 1 + n, cmp2);
	else sort(a + 1, a + 1 + n, cmp3);
	for (int i = 1; i <= n; i++) {
		int j = a[i].xdmax;
		if (cnt[j] <= sx) {
			cnt[j]++;
			g[numc][j] += a[i].num[j];
		}
		if (cnt[j] == sx) {
			gsx[j] = g[numc][j];
		} 
		else {
			int maxnls = -10000;
			for (int k = 1; k <= 3; k++) {
				if (k == j)continue;
				else if (gsx[k] > maxnls) maxnls = gsx[k];
			}
			g[numc][j] = max(g[numc][j], a[i].num[j] + maxnls);
			//for(int i=1;i<=3;i++){
				//cout <<g[numc][i]<<" ";
			//}
			//cout <<endl;
		}
	}
	for (int i = 1; i <= 3; i++) {
		maxnl = max(g[numc][1], max(g[numc][2], g[numc][3]));
	}
}
int main() { 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin >> t;
	while (t--) {
		int maxn = -100000;
		cin >> n;
		sx = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].num[1] >> a[i].num[2] >> a[i].num[3];
			int maxn = max(a[i].num[1], max(a[i].num[2], a[i].num[3]));
			if (maxn == a[i].num[1]) a[i].xdmax = 1;
			if (maxn == a[i].num[2]) a[i].xdmax = 2;
			else a[i].xdmax = 3;
		}
		for (int i = 1; i <= 3; i++) {
			pzd(a, i);
			maxn = max(maxnl, maxn);
		}
		cout << maxn << endl;
	}
	
return 0;
}