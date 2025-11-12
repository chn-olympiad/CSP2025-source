#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int N=1e4+15,M=2e6+5;
int n,m,k;
int fa[N],siz[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct Edge{
	int u,v,w;
	bool operator<(const Edge&_)const{
		return w<_.w;
	}
}e[M],te[M],a[M],se;int ecnt,Ecnt,acnt,c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;e[++ecnt]={u,v,w};
	}
	sort(e+1,e+ecnt+1);
	rep(i,1,n)fa[i]=i,siz[i]=1;
	rep(i,1,ecnt){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v)fa[u]=v,e[++Ecnt]=e[i];
	}
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n){
			int v;cin>>v;
			a[++acnt]={n+i,j,v};
		}
	}
	sort(a+1,a+acnt+1);
	ll ans=1e18;
	rep(s,0,(1<<k)-1){
		ecnt=0;ll tans=0;int cnt=Ecnt;
		rep(i,1,k)if(s&(1<<i-1)){
			tans+=c[i];
		}
		rep(i,1,acnt)if(s&(1<<a[i].u-n-1))te[++ecnt]=a[i],cnt++;
		int p1=1,p2=1;
		rep(i,1,n+k)fa[i]=i,siz[i]=1;
		e[Ecnt+1].w=te[ecnt+1].w=2e9;
		rep(i,1,cnt){
			if(e[p1]<te[p2])se=e[p1],p1++;
			else se=te[p2],p2++;
			int u=find(se.u),v=find(se.v);
			if(u!=v){
				if(siz[u]<siz[v])fa[u]=v,siz[v]+=siz[u];
				else fa[v]=u,siz[u]+=siz[v];
				tans+=se.w;	
			}
			if(tans>=ans)break;
		}
		ans=min(ans,tans);
	}
	printf("%lld",ans);
	return 0;
}