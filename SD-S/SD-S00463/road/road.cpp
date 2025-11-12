#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,mod=998244353;
int n,m,k;
struct edge{
	int u,v,w;
}ed[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
vector<int> e[N],w[N];
long long c[N],a[N][N],ans;
bool vis[N],vik[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(ed+1,ed+1+n,cmp);
	if(k==0){
		for(int i=1;i<=m;i++){
			if(vis[ed[i].u]&&vis[ed[i].v]) continue;
			else{
				int u=ed[i].u,v=ed[i].v;
				e[u].push_back(v);
				e[v].push_back(u);
				ans+=ed[i].w;
				vis[u]=vis[v]=1;
			}
		}
	}
	else{
		for(int i=1;i<=m;i++){
			if(vis[ed[i].u]&&vis[ed[i].v]) continue;
			else{
				int u=ed[i].u,v=ed[i].v;
				int minw=ed[i].w,pk=20;
				for(int i=1;i<=k;i++){
					if(vik[i]==0){
						if(a[i][u]+a[i][v]+c[i]<minw){
							minw=a[i][u]+a[i][v]+c[i];
							pk=i;
						}	
					}
					else{
						if(a[i][u]+a[i][v]<minw){
							minw=a[i][u]+a[i][v];
							pk=i;
						}
					} 
				}
				if(pk<=k) vis[pk]=1;
				e[u].push_back(v);
				e[v].push_back(u);
				ans+=minw;
				vis[u]=vis[v]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
