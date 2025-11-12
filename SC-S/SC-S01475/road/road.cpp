#include <bits/stdc++.h>
#define int long long
using namespace std;
struct P{
	int u,v,w;
};
int n,m,k;
long long anss=1e18;
int fa[10005];
vector <P> e;
int cnt[15];
vector <P> ans;
bool vis[15];
bool cmp(P x,P y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		e.push_back({u,v,c});
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	
	long long res=0;
	
	sort(e.begin(),e.end(),cmp);
	
	for(int i=0;i<e.size();i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fx=find(u);
		int fy=find(v);
		if(fx==fy) continue;
		fa[fx]=fy;
		res+=w;
	}
	anss=res,res=0;
	
	
	if(k){
		for(int i=1;i<=k;i++){
			cin>>cnt[i];
			for(int j=1;j<=n;j++){
				int c;
				cin>>c;
				e.push_back({n+i,j,c+cnt[i]});
			}
		}
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(e.begin(),e.end(),cmp);
		int fini=1;
		for(int i=0;i<e.size();i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fx=find(u);
			int fy=find(v);
			if(fx==fy) continue;
			fa[fx]=fy;
			if(u<=n && v<=n) fini++;
			res+=w;
			ans.push_back({u,v,w});
			//if(fini>=n) break;
		}
		
		for(int i=0;i<ans.size();i++){
			int u=ans[i].u,v=ans[i].v,w=ans[i].w;
			if(u>n){
				u=u-n;
				res-=cnt[u];
				vis[u]=1;
			}
			else if(v>n){
				v=v-n;
				res-=cnt[v];
				vis[v]=1;
			}
		}
		for(int i=1;i<=k;i++){
			if(vis[i]) res+=cnt[i];
		}
		anss=min(anss,res);
	}
	cout<<anss<<endl;
	return 0;
	
} 