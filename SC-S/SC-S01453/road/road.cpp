#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
typedef long long ll;
typedef double ld;
namespace io {
	using namespace std;
	inline int read() {
		char x=getchar();
		int ans=0,f=1;
		while(x<'0'||x>'9') {
			if(x=='-') {
				f*=(-1);
			}
			x=getchar();
		}
		while(x>='0'&&x<='9') {
			ans*=10;
			ans+=(x-'0');
			x=getchar();
		}
		return ans*f;
	}
}
using namespace io;
const ll N=1e4+5,mod=1e9+7,inf=2e18;
const ld eps=1e-6;
struct node {
	int ul,vl,wl;
} num[1000005],kl[1000005],cl[2000005];
int n,m,k,cnt,a[15][N],val[15],sl[15],f[N];
ll ans;
ll find(ll x) {
	if(x==f[x]) {
		return x;
	}
	return f[x]=find(f[x]);
}
inline void solve() {
	n=read(),m=read(),k=read();
	for(ll i=1;i<=n;i++) {
		f[i]=i;
	}
	for(ll i=1;i<=m;i++) {
		int ul,vl,wl;
		ul=read(),vl=read(),wl=read();
		num[i]={ul,vl,wl};
	}
	for(ll i=1;i<=k;i++) {
		val[i]=read();
		sl[i]=0;
		ll mn=inf;
		for(ll j=1;j<=n;j++) {
			a[i][j]=read();
			if(a[i][j]<=mn) {
				sl[i]=j;
				mn=a[i][j];
			}
		}
	}
	sort(num+1,num+1+m,[](node a,node b) {
		return a.wl<b.wl;
	});
	for(ll i=1;i<=m;i++) {
		node it=num[i];
		ll ul=it.ul,vl=it.vl,wl=it.wl;
		ll fu=find(ul),fv=find(vl);
		if(fu==fv) {
			continue;
		}
		kl[++cnt]=it;
		f[fv]=fu;
		ans+=wl;
		if(cnt==n-1) {
			break;
		}
	}
	for(ll s=1;s<(1<<k);s++) {
		ll ql=0;
		for(ll i=1;i<n;i++) {
			cl[i]=kl[i];
		}
		ll el=n-1;
		for(ll i=1;i<=k;i++) {
			if(!((1<<i-1)&s)) {
				continue;
			}
			ql+=val[i];
			for(ll j=1;j<=n;j++) {
				if(sl[i]==j) {
					continue;
				}
				cl[++el]={sl[i],j,a[i][sl[i]]+a[i][j]};
			}
		}
		for(ll i=1;i<=n;i++) {
			f[i]=i;
		}
		sort(cl+1,cl+1+el,[](node a,node b) {
			return a.wl<b.wl;
		});
		ll pl=el;
		el=0;
		for(ll i=1;i<=pl;i++) {
			node it=cl[i];
			ll ul=it.ul,vl=it.vl,wl=it.wl;
			ll fu=find(ul),fv=find(vl);
			if(fu==fv) {
				continue;
			}
			f[fv]=fu;
			el++;
			ql+=wl;
			if(el==n-1) {
				break;
			}
		}
		ans=min(ans,ql);
	}
	cout<<ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll T=1;
//	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/