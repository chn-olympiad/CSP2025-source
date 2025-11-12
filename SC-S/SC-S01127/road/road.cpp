#include<bits/stdc++.h>
#define ll long long
#define N (int)1e3+5
#define M (int)3e7+5
#define inf (ll)1e18+1
using namespace std;
ll n,m,k,ans=inf;
ll c[15];
ll dis[N];
struct Road{
	ll x,y,w;
	ll flag;
	bool operator <(const Road &_t)const{
		return w<_t.w;
	}
};
Road e[M]; 
ll fa[N];
ll findroot(ll x){
	if(fa[x]!=x)fa[x]=findroot(fa[x]);
	return fa[x];
}
void addedge(ll x,ll y){
	if(findroot(x)==findroot(y))return ;
	fa[fa[x]]=fa[y];
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t1=clock();
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].w;
		e[i].flag=0;
	}
//	cout<<clock()-t1<<'\n';
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int x=1;x<=n;x++){
			cin>>dis[x];
			for(int y=1;y<x;y++){
				e[++m]={x,y,dis[x]+dis[y],i};
				continue; 
			}
		}
	}
//	cout<<clock()-t1<<'\n';
//	cout<<m<<'\n';
	sort(e+1,e+1+m);
//	cout<<clock()-t1<<'\n';
	for(int i=0;i<(1<<k);i++){
		
		ll ret=0,cnt=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				ret+=c[j+1];
			}
		}
//		cout<<ret<<' ';
		for(int j=1;j<=n;j++){
			fa[j]=j;
		}
		for(int j=1;cnt<n-1;j++){
			ll x=e[j].x;
			ll y=e[j].y;
			ll w=e[j].w;
			if(e[j].flag&&!(i&(1<<(e[j].flag-1))))continue;
			if(findroot(x)==findroot(y))continue;
			addedge(x,y);
			cnt++;
			ret+=w;
//			cout<<w<<' ';
		}
		ans=min(ans,ret);
//		cout<<ret<<'\n';
	}
	cout<<ans;
//	cout<<'\n'<<clock()-t1;
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