#include<iostream>
#include<algorithm>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5;
using namespace std;
int t,n,ans,cnt[10];
pii a[N+5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			pii p[10];
			cin>>p[1].fi>>p[2].fi>>p[3].fi;
			p[1].se=1;
			p[2].se=2;
			p[3].se=3;
			sort(p+1,p+4);
			cnt[p[3].se]++;
			ans+=p[3].fi;
			a[i]={p[2].fi-p[3].fi,p[3].se};
		}
		int maxx=1;
		if(cnt[2]>cnt[maxx]) maxx=2;
		if(cnt[3]>cnt[maxx]) maxx=3;
		for(int i=1;i<=n;i++)
			if(a[i].se!=maxx)
				a[i]={0,0};
		sort(a+1,a+n+1);
		for(int i=n/2+1;i<=n;i++)
			ans+=a[i].fi;
		cout<<ans<<"\n";
	}
	return 0;
}
