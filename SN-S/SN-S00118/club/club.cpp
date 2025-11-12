//吴红燊 SN-S00118 西安湖滨中学
/*
luogu uid:743127
this is the way I still love something
bye,someone
CSP-S2025 RP++
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int T = 2e5+10,inf = 1e18;
int n,a[T][4];
int cnt[4];
int dai[T],g = 0;
void solve() {
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	g = 0;
	cin >> n;
	int zans = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			cnt[1]++;
			zans += a[i][1];
		}
		else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			cnt[2]++;
			zans += a[i][2];
		}
		else {
			cnt[3]++;
			zans += a[i][3];
		}
	}
	if(cnt[1] <= n/2 && cnt[2] <= n/2 && cnt[3] <= n/2) {
		cout << zans << '\n';
		return ;
	}
	int h = -1;
	if(cnt[1] > n/2) h = 1;
	else if(cnt[2] > n/2) h = 2;
	else h = 3;
	
	int yu = cnt[h] - n/2;
	for(int i = 1;i <= n;i++) {
		if(a[i][h] >= max(max(a[i][1],a[i][2]),a[i][3])) {
			int v = 0;
			for(int j = 1;j <= 3;j++) {
				if(j == h) continue;
				v = max(v,a[i][j]);
			}
			dai[++g] = a[i][h]-v;
		}
	}
	sort(dai+1,dai+g+1);
	for(int i = 1;i <= yu;i++) {
		zans -= dai[i];
	}
	cout << zans << '\n';
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--)
	solve();
	return 0;
}
