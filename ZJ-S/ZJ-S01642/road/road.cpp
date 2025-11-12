#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

using namespace std;
struct edge{
	int x,y;
	ll w;
};
const int N=1e4,M=1e6,K=10;
int n,m,k;
ll a[K+5][N+5],d[N+5];
int fa[N+5],flag[N+5];
ll ans,add;
edge e[M+5];
vector< pair<int,ll> > r[N+5];
bool cmp(edge x,edge y){
	return x.w<y.x;
}
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
ll prim(int x){
	for(int i=1;i<=n;i++)
		d[i]=1e18,flag[i]=0;
	flag[1]=1;
	for(int i=0;i<r[1].size();i++){
		pair<int,ll> y=r[1][i];
		d[y.fir]=min(d[y.fir],y.sec);
	}
	for(int i=0;i<k;i++){
		if((x>>i)&1){
			for(int j=2;j<=n;j++){
				d[j]=min(d[j],a[i+1][1]+a[i+1][j]);
			}
		}
	}
	ll ret=0;
	for(int i=2;i<=n;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(flag[j]) continue;
			if(t==0) t=j;
			else{
				if(d[t]>d[j]) t=j;
			}
		}
		ret+=d[t]; flag[t]=1;
		for(int j=0;j<r[t].size();j++){
			pair<int,ll> y=r[t][j];
			if(!flag[y.fir]) d[y.fir]=min(d[y.fir],y.sec);
		}
		for(int l=0;l<k;l++){
			if((x>>l)&1){
				for(int j=1;j<=n;j++){
					if(!flag[j]&&j!=t) d[j]=min(d[j],a[l+1][t]+a[l+1][j]);
				}
			}
		}
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	int u,v; ll w;
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		if(k!=0){
			r[u].pb(mp(v,w));
			r[v].pb(mp(u,w));
		}
		else e[i].w=w,e[i].x=u,e[i].y=v;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	if(k==0){
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			int x=find(e[i].x),y=find(e[i].y);
			if(x==y) continue;
			ans+=e[i].w;
			fa[x]=fa[y];
		}
		printf("%lld",ans);
		return 0;
	}
	ans=1e18;
	for(int i=0;i<(1<<k);i++){
		add=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1)
				add+=a[j+1][0];
		}
		ans=min(prim(i)+add,ans);
	}
	printf("%lld",ans);
	
	return 0;
}
