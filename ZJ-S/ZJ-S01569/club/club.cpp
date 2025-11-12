#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,cnt[4];
struct node {
	int fir;
	int fig;
	int sec;
	int seg;
} abc[214514];
bool cmp(node x,node y) {
	return (x.fir-x.sec)>(y.fir-y.sec);
}
void solve() {
	cin>>n;
	pair<int,int> a[3];
	for(int i=1;i<=n;i++) {
		for(int j=0;j<3;j++) {
			cin>>a[j].first;
			a[j].second=j;
		}
		sort(a,a+3);
		abc[i].fir=a[2].first,abc[i].fig=a[2].second;
		abc[i].sec=a[1].first,abc[i].seg=a[1].second;//get the max and sec_max
	}
	
	memset(cnt,0,sizeof(cnt));
	sort(abc+1,abc+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++) {
		if(cnt[abc[i].fig]<n/2) {
			ans+=abc[i].fir;
			cnt[abc[i].fig]++;
		}
		else {
			ans+=abc[i].sec;
			cnt[abc[i].seg]++;
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}
//help me ac this