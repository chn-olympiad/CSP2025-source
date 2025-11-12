#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n,m,k;
struct edge{
	ll u,v,w;
}e[100005],ee[100005];
bool cmp(edge a,edge  b){
	return a.w<b.w;
}
ll f[20004];
ll finf(ll x){
	if(f[x]==x){
		return f[x];
	}
	return f[x]=finf(f[x]);
}
ll ww[11][10004],uu[10004];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(ll i=1;i<=k;i++){
		cin>>uu[i];
		for(ll j=1;j<=n;j++){
			cin>>ww[i][j];
		}
	}
	ll anss=LONG_LONG_MAX; 
	for(ll i=0;i<=(1<<(k))-1;i++){
		ll cnt=0,ans=0,cntt=0;
		for(ll j=1;j<=n+k;j++){
			f[j]=j;
		}
		for(ll j=1;j<=m;j++){
			ee[++cnt]=e[j];
		}
		for(ll j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				for(ll o=1;o<=n;o++){
					e[++cnt]={n+j,o,ww[j][o]};
				}
				ans+=uu[j];
			}
		}
		sort(ee+1,ee+cnt+1,cmp);
		for(ll j=1;j<=cnt;j++){
			ll fx=finf(ee[j].u);
			ll fy=finf(ee[j].v);
			if(fx!=fy){
				f[fx]=fy;
				cntt++;ans+=ee[j].w;
			}
		}
		anss=min(anss,ans);
	}
	cout<<anss;
	return 0;
}

