#include<bits/stdc++.h>
#define int long long
using namespace std;
int cmp(int x,int y) {
	return x>y;
}
int a[4][100005],cnt[4],b[100005];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=1;i<=n;i++) {
			int maxx=0;
			maxx=max(a[1][i],a[2][i]);
			maxx=max(maxx,a[3][i]);
			if(maxx==a[1][i]) cnt[1]++;
			if(maxx==a[2][i]) cnt[2]++;
			if(maxx==a[3][i]) cnt[3]++;
		}
		int maxxx=0,p=0;
		maxxx=max(cnt[1],cnt[2]);
		maxxx=max(maxxx,cnt[3]);
		if(maxxx==cnt[1]) p=1;
		if(maxxx==cnt[2]) p=2;
		if(maxxx==cnt[3]) p=3;
		int ans=0;
		for(int i=1;i<=n;i++) {
			ans+=a[p][i];
		}
		for(int i=1;i<=n;i++) {
			b[i]=-1000000;
			for(int j=1;j<=3;j++) {
				if(j==p) continue;
				b[i]=max(b[i],a[j][i]-a[p][i]);
			}
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++) {
			if(i<=(n/2)||b[i]>0)
			ans+=b[i];
			else break;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
