#include <bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int n,a[N][4],b[N];
vector<int> d1,d2,d3;
void solve () {
	scanf("%lld",&n);
	for (int i=1;i<=n;++i) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	int res=0;
	d1.clear();
	d2.clear();
	d3.clear();
	for (int i=1;i<=n;++i) {
		int mx=max(a[i][1],max(a[i][2],a[i][3]));
		if (mx==a[i][1]) d1.push_back(i);
		else if (mx==a[i][2]) d2.push_back(i);
		else d3.push_back(i);
		res+=mx;
	}
	if (d1.size()>n/2) {
		for (int i=0;i<d1.size();++i) {
			int x=d1[i];
			int md=a[x][1]+a[x][2]+a[x][3]-max(a[x][1],max(a[x][2],a[x][3]))-min(a[x][1],min(a[x][2],a[x][3]));
			b[i+1]=max(a[x][1],max(a[x][2],a[x][3]))-md;
		}
		sort(b+1,b+d1.size()+1);
		for (int i=1;i<=d1.size()-n/2;++i) res-=b[i];
	}
	if (d2.size()>n/2) {
		for (int i=0;i<d2.size();++i) {
			int x=d2[i];
			int md=a[x][1]+a[x][2]+a[x][3]-max(a[x][1],max(a[x][2],a[x][3]))-min(a[x][1],min(a[x][2],a[x][3]));
			b[i+1]=max(a[x][1],max(a[x][2],a[x][3]))-md;
		}
		sort(b+1,b+d2.size()+1);
		for (int i=1;i<=d2.size()-n/2;++i) res-=b[i];
	}
	if (d3.size()>n/2) {
		for (int i=0;i<d3.size();++i) {
			int x=d3[i];
			int md=a[x][1]+a[x][2]+a[x][3]-max(a[x][1],max(a[x][2],a[x][3]))-min(a[x][1],min(a[x][2],a[x][3]));
			b[i+1]=max(a[x][1],max(a[x][2],a[x][3]))-md;
		}
		sort(b+1,b+d3.size()+1);
		for (int i=1;i<=d3.size()-n/2;++i) res-=b[i];
	}
	printf("%lld\n",res);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%lld",&T);
	while (T--) solve();
	return 0;
}