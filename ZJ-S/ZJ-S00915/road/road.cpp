#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
int n,m,k,len=0,fa[10100],c[11][10011];
struct node{int u,v,w;}e[1100010],tmp[1100010];
bool cmp(node i,node j){return i.w<j.w;}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int kruskal(int pls){
	int cnt=0,res=0;
	For(i,1,len+pls*n){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y;
		res+=e[i].w;
		if(++cnt==n+pls-1) break;
	}
	return res;
}
bool vis[15];
int ans=LLONG_MAX;
void dfs(int x){
	if(x==k+1){
		For(i,1,len) e[i]=tmp[i];
		int res=0,plsl=0;
//		cout<<"---------------------------\n";
//		For(i,1,k) cout<<vis[i]<<" "; cout<<"\n";
		For(i,1,k) if(vis[i]){
			res+=c[i][0];
			++plsl;
			For(j,1,n){
				e[(plsl-1)*n+j+len]={n+plsl,j,c[i][j]};
			}
		}
		sort(e+1,e+1+n*plsl+len,cmp);
//		cout<<plsl<<"\n";
//		For(i,1,n*plsl+len) cout<<i<<" "<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
		memset(fa,0,sizeof(fa));
		For(i,1,n+plsl) fa[i]=i;
//		cout<<"res:"<<res<<"\n";
		res+=kruskal(plsl);
//		cout<<"res:"<<res<<"\n";
		ans=min(ans,res);
		return ;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	For(i,1,m) {
		int u,v,w;
		cin>>u>>v>>w;
		e[++len]={u,v,w};
	}
	For(i,1,len) tmp[i]=e[i];
	For(i,1,k) For(j,0,n) cin>>c[i][j];
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}

