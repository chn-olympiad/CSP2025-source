#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
using namespace std;
const int N=1e4+20,M=1e6+5,K=30;
struct Ed{int u,v,w;}e[M+K*N];
int n,m,k,idx,c[K],a[K][N],fa[N+K],ans;
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool cmp(Ed a,Ed b){return a.w<b.w;}
bitset<K> vis;
bool SPE=1;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++idx]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) SPE=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++idx]={n+i,j,a[i][j]};
		}
	}
	if(SPE){//40pts 性质A 直接MST
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(e+1,e+1+idx,cmp);
		for(int i=1;i<=idx;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			u=find(u),v=find(v);
			if(u==v) continue;
			fa[u]=v,ans+=w;
		}
		cout<<ans<<"\n";
	}else if(k<=5){//30pts k<=5 直接枚举+MST
		ans=1e18;
		sort(e+1,e+1+idx,cmp);
		for(int i=(1<<k)-1;~i;i--){
			int sum=0;
			for(int j=0;j<k;j++){
				vis[j+1]=((i>>j)&1);
				if(vis[j+1]) sum+=c[j+1];
			}//vis即被选择 
			for(int j=1;j<=n+k;j++) fa[j]=j;
			for(int j=1;j<=idx;j++){
				int u=e[j].u,v=e[j].v,w=e[j].w;
				if(u>n&&!vis[u-n]) continue;
				u=find(u),v=find(v);
				if(u==v) continue;
				fa[u]=v,sum+=w;
			}
			ans=min(ans,sum);
		}
		cout<<ans<<"\n";
	}else{//0pts 直接MST 
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(e+1,e+1+idx,cmp);
		for(int i=1;i<=idx;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			u=find(u),v=find(v);
			if(u==v) continue;
			fa[u]=v,ans+=w;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
