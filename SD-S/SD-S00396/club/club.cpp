#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 100;
int a[maxn][4];
int n;
int lm;
int rak[maxn][4];
int vis[4];

int dv[maxn][5];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;	
	while(t --) {
		memset(rak, 0, sizeof(rak));
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		vector<int>selct[4];
		cin >> n;
		int ans = 0;
		lm = n/2;
		for(int i = 1; i<=n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int am = 0, bm = 0, cm = 0;
			for(int j = 1; j<=3; j++) {
				if(a[i][j] >= a[i][am]) {
					cm = bm;
					bm = am;
					am = j;
				} else if(a[i][j] >= a[i][bm]) {
					cm = bm;
					bm = j;
				} else if(a[i][j] >= a[i][cm]) {
					cm = j;
				}
			}
			rak[i][1] = am; rak[i][2] = bm; rak[i][3] = cm;
		}
		/*for(int i = 1; i<=n; i++) {
			cout<<i<<":";
			for(int j = 1; j<=3; j++) {
				cout<<rak[i][j]<<' ';
			} cout<<'\n';
		}*/
		
		for(int i = 1; i<=n; i++) {
			selct[rak[i][1]].push_back(i);
			ans += a[i][rak[i][1]];
		}
		int dax[4];
		dax[1] = selct[1].size();
		dax[2] = selct[2].size();
		dax[3] = selct[3].size();
		for(int i = 1; i<=3; i++) {
			if(dax[i] >= lm) vis[i] = 1;
		}
		//cout << dax[1]<<'\n';
		//cout<<dax[2]<<'\n';
		for(int i = 1; i<=n; i++) {
			dv[i][1] = 0;
			dv[i][2] = a[i][rak[i][1]] - a[i][rak[i][2]];
			dv[i][3] = a[i][rak[i][1]] - a[i][rak[i][3]];
		}
		vector<int>ut;
		for(int i = 1; i<=3; i++) {
			if(dax[i] > lm) {
				int pos = dax[i] - lm;
				for(int j = 0; j<selct[i].size(); j++) {
					int stu = selct[i][j];
					ut.push_back(min(dv[stu][2], dv[stu][3]));
				}
				sort(ut.begin(), ut.end());
				for(int i = 0; i<pos; i++) {
					ans -= ut[i];
				}
				break;
			}
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}


// Ren5Jie4Di4Ling5%
