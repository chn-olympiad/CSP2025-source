#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
const int N = 1e5+5, INF = 2.1e9;

int n, t, a[N][3], c[N], mx[N], ans, clb;
vector<int> shetuan[3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while(t--) {
		for(int i=0;i<3;++i) shetuan[i].clear();
		cin>>n;
		for(int i=0;i<=n;++i) c[i] = mx[i] = -INF;
		ans = 0;
		int n2 = n>>1;
		for(int i=1,mi;i<=n;++i) {
			for(int j=0;j<3;++j) {
				cin>>a[i][j];
				if(a[i][j]>mx[i]) {
					mx[i] = a[i][j];
					mi = j;
				}
			}
			shetuan[mi].push_back(i);
			ans += mx[i];
		}
		int cnt2=-1;
		for(int i=0,sz;i<3;++i) {
			sz = shetuan[i].size();
			if(sz>cnt2) {
				clb = i;
				cnt2 = sz;
			}
		}
		if(cnt2<=n2) cout<<ans<<'\n';
		else {
			for(int j=0;j<cnt2;++j) {
				int x = shetuan[clb][j];
				for(int i=0;i<3;++i) {
					if(i!=clb && a[x][i]-mx[x]>c[j]) c[j] = a[x][i]-mx[x];
				}
			}
			sort(c, c+cnt2);
			for(int i=n2;i<cnt2;++i) {
				ans += c[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 