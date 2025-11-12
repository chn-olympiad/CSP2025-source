#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=1;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int xx=1e6+5;
const int P=1e9+7;
struct node{
	int u,v,w;
}e[xx<<2];

int fa[xx],sizes[xx];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	if(sizes[fx]<sizes[fy]){
		fa[fx]=fy;
		sizes[fy]+=sizes[fx];
	}
	else{
		fa[fy]=fx;
		sizes[fx]+=sizes[fy];
	}
}
int c[15];
int a[15][xx];
int n,m,k;
bool vis[xx];
map<pair<int,int>,int> mp;
bool vis2[xx<<2];
bool cmp(node a,node b){
	return a.w<b.w;
}
int cnt=0;
int kruskal(){
	sort(e+1,e+cnt+1,cmp);
//	for(int i=1;i<=cnt;++i){
	//	cout<<e[i].w<<'\n';
//	}
	int cn=0,ans=0;
	for(int i=1;cn!=n-1;++i){
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		merge(fu,fv);
		if(vis2[mp[{u,v}]]&&!vis[u]&&!vis[v]){
			if(u<=k&&v<=k){
				ans+=min(c[u],c[v]);
				if(c[u]<c[v]) vis[u]=1;
				else vis[v]=1;
			}
			else if(u>=k){
				ans+=c[u];	
				vis[u]=1;
			} 
			else{
				ans+=c[v];
				vis[v]=1;
			}
		}
		ans+=e[i].w;
		//cout<<u<<' '<<v<<' '<<e[i].w<<'\n';
		cn++;
	}
	return ans;
}
void solve()
{
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
		mp[{u,v}]=mp[{v,u}]=i;
	}
	cnt=m;
	for(int i=1;i<=n;++i){
		fa[i]=i;
		sizes[i]=1;
	}
	mp.clear();
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			if(!mp[{i,j}]||(mp[{i,j}]&&a[i][j]<e[mp[{i,j}] ].w)){
				if(!mp[{i,j}]){
					cnt++;
					mp[{i,j}]=mp[{j,i}]=cnt;
					vis2[cnt]=1;
				}
				e[mp[{i,j}] ].w=a[i][j]; 
			}
		}
	}
	int maxx=kruskal();
	cout<<maxx<<'\n';
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}

