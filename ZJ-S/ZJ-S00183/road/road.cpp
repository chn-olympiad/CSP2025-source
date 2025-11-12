#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,c[20],f[12000],nw[20],tot,cnt,ans,s,sss[20];
pair<ll,pair<ll,ll> >tu[10100],e[1001000];
pair<ll,ll>b[20][10100];
ll fnd(ll lx){
	if(f[lx]==lx) return lx;
	else return f[lx]=fnd(f[lx]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[++tot]=make_pair(w,make_pair(u,v));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>b[i][j].first,b[i][j].second=j;
		sort(b[i]+1,b[i]+n+1);
	}
	sort(e+1,e+tot+1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		ll fa=fnd(e[i].second.first),fb=fnd(e[i].second.second);
		if(fa==fb) continue;
		ans+=e[i].first;
		f[fb]=fa;
		tu[++cnt]=e[i];
	}
	for(int S=1;S<(1<<k);S++){
		s=0;
		ll d=0;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=k;i++)
			if(S&(1<<(i-1))){
				s+=c[i];
				nw[i]=1;
				d++;
				sss[d]=i;
			}
			else nw[i]=n+1;
		nw[0]=1;
		for(int i=1;i<n+d;i++){
			while(nw[0]<n&&fnd(tu[nw[0]].second.first)==fnd(tu[nw[0]].second.second)) nw[0]++;
			for(int j=1;j<=d;j++) while(nw[sss[j]]<=n&&fnd(sss[j]+n)==fnd(b[sss[j]][nw[sss[j]]].second)) nw[sss[j]]++;
			ll su=0,sv=0,mi=LLONG_MAX;
			if(nw[0]<n) su=tu[nw[0]].second.first,sv=tu[nw[0]].second.second,mi=tu[nw[0]].first;
			for(int j=1;j<=d;j++) if(nw[sss[j]]<=n&&mi>b[sss[j]][nw[sss[j]]].first) mi=b[sss[j]][nw[sss[j]]].first,su=n+sss[j],sv=b[sss[j]][nw[sss[j]]].second;
			ll fa=fnd(su),fb=fnd(sv);
			s+=mi;
			f[fb]=fa;
		}
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}