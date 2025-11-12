#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
const ll N=1e5+10;
ll t,n,a[N][3],mcnt[3],ma[N],mk[N],b[N],vec[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0;
		for(int i=0;i<3;i++) mcnt[i]=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ma[i]=max(a[i][0],max(a[i][1],a[i][2]));
			ll nma=0,k=-1;
			for(int j=0;j<3;++j)
				if(a[i][j]==ma[i])
					k=j;
//			cout<<k<<' ';
			for(int j=0;j<3;++j)
				if(j!=k)
					nma=max(nma,a[i][j]);
			mcnt[k]++,b[i]=ma[i]-nma,ans+=ma[i],mk[i]=k;
		}
		ll k=-1,cnt=0;
		for(int i=0;i<3;i++) if(mcnt[i]>n/2) k=i;
//		cout<<k<<' ';
		if(k!=-1){
			for(int i=1;i<=n;i++)
				if(mk[i]==k)
					vec[++cnt]=b[i];
			sort(vec+1,vec+1+cnt);
			for(int i=1;i<=cnt-n/2;i++) ans-=vec[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
