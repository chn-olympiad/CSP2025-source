#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define pb push_back
#define eb emplace_back
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define lb(x) ((x)&(-x))
#define rg register
using namespace std;
const int N=1e4+20,M=1e6+1e5+20,P=20;
const ll INF=1ll<<60,mod=998244353;
int n,m,k,c[P],a[P][N],fa[N],tot[P],pot[P];
struct edge{
	int u,v,w;
}e[M],E[N],ep[P][N];
inline bool operator < (const edge xx,const edge yy){
	return xx.w<yy.w;
}
ll ans,sum;
inline int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int yy[P],oo[P],s[P];
edge Cnt[M];
inline int Sort(int l,int r){
	if(l==r) return s[l]-s[l-1];
	int mid=(l+r)>>1;
	int L=Sort(l,mid),R=Sort(mid+1,r);
	merge(e+s[l-1]+1,e+s[l-1]+L+1,e+s[mid]+1,e+s[mid]+1+R,Cnt+1);
	for(rg int i=1;i<=L+R;i++) e[s[l-1]+i]=Cnt[i];
	return s[r]-s[l-1];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IOS;cin>>n>>m>>k;
	iota(fa+1,fa+1+n+k,1);
	for(rg int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(rg int i=1;i<=k;i++){
		cin>>c[i];
		for(rg int j=1;j<=n;j++){
			cin>>a[i][j];
			ep[i][j]={n+i,j,a[i][j]};
		}
		sort(ep[i]+1,ep[i]+1+n);
	}
	sort(e+1,e+1+m);
	int cnt=0;
	for(rg int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		sum+=w;fa[fu]=fv;E[++cnt]={u,v,w};
	}
	ans=sum;
	s[1]=cnt;
	for(rg int i=1;i<=k;i++) s[i+1]=s[i]+n;
	for(rg int t=1;t<=(1<<k)-1;t++){
		iota(fa+1,fa+1+n+k,1);
		ll tp=0;
		int res=0;
		for(rg int i=1;i<=k;i++){
			if((t>>(i-1))&1) pot[++res]=i,tp+=c[i];
		}
		int ttt=cnt;
		for(rg int i=1;i<=cnt;i++) e[i]=E[i];
		for(rg int i=1;i<=res;i++){
			for(rg int j=1;j<=n;j++){
				e[++ttt]=ep[pot[i]][j];
			}
		}
		Sort(1,res+1);
		for(rg int i=1;i<=ttt;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fu=find(u),fv=find(v);
			if(fu^fv) tp+=w,fa[fu]=fv;			
		}
		ans=min(ans,tp);
	}
	cout<<ans<<"\n";
	return 0;
}

