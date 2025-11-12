#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[3000005],d[3000005];
int f[500005];
int c[15];
int b[10005][15];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
vector<pair<int,int>>e[30005];
int dep[50005];
int dis[50005];
int fa[50005][21];
void dfs(int u,int ff){
	dis[u]=dis[ff]+1;
	fa[u][0]=ff;
	for(int i=1;i<=20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(auto j:e[u]){
		int v=j.first;
		if(v==ff){
			continue;
		}
		dep[v]=dep[u]+j.second;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dis[u]<dis[v]){
		swap(u,v);
	}
	for(int i=20;i>=0;i--){
		if(dis[fa[u][i]]>=dis[v]){
			u=fa[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=20;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	dis[1]=1;
	dep[1]=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	int l=(1<<k)-1;
	bool fff=true;
	for(int i=0;i<k;i++){
		cin>>c[i];
		if(c[i]!=0){
			fff=false;
		}
		bool ff=true;
		for(int j=1;j<=n;j++){
			cin>>b[j][i];
			if(b[j][i]==0){
				ff=false;
			}
		}
		if(ff){
			fff=false;
		}
	}
	long long res=1e18;
	if(fff){
		for(int S=l;S<=l;S++){
			int tot=m;
			for(int i=1;i<=m;i++){
				d[i]=a[i];
			}
			long long cnt=0;
			for(int i=0;i<k;i++){
				if(((1<<i)&S)!=0){
					cnt+=c[i];
					for(int j=1;j<=n;j++){
						d[++tot]={n+i+1,j,b[j][i]};
					}
				}
			}
			for(int i=1;i<=n+k;i++){
				f[i]=i;
			}
			sort(d+1,d+tot+1,cmp);
			for(int i=1;i<=tot;i++){
				int u=find(d[i].u);
				int v=find(d[i].v);
				if(u!=v){
					f[u]=v;
					cnt+=d[i].w;
				}
			}
			res=min(res,cnt);
		}
		cout<<res<<endl;
		return 0;
	}
	if(m<=100000&&k<=6){
		for(int S=0;S<=l;S++){
		int tot=m;
		for(int i=1;i<=m;i++){
			d[i]=a[i];
		}
		long long cnt=0;
		for(int i=0;i<k;i++){
			if(((1<<i)&S)!=0){
				cnt+=c[i];
				for(int j=1;j<=n;j++){
					d[++tot]={n+i+1,j,b[j][i]};
				}
			}
		}
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		sort(d+1,d+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			int u=find(d[i].u);
			int v=find(d[i].v);
			if(u!=v){
				f[u]=v;
				cnt+=d[i].w;
			}
		}
		res=min(res,cnt);
	}
	cout<<res<<endl;
	return 0;
	}
	for(int S=0;S<=0;S++){
		int tot=m;
		for(int i=1;i<=m;i++){
			d[i]=a[i];
		}
		long long cnt=0;
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		sort(d+1,d+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			int u=find(d[i].u);
			int v=find(d[i].v);
			if(u!=v){
				f[u]=v;
				cnt+=d[i].w;
				e[d[i].u].push_back({d[i].v,d[i].w});
				e[d[i].v].push_back({d[i].u,d[i].w});
			}
		}
		res=min(res,cnt);
	}
	dfs(1,0);
	vector<int>use;
	for(int ll=0;ll<k;ll++){
		bool ff=true;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!ff){
					break;
				}
				int p=lca(i,j);
				int u=dep[i]-dep[p]*2+dep[j];
				int uu=b[i][ll]+b[j][ll]+c[ll];
				if(uu<u){
					ff=false;
					use.push_back(ll);
				}
			}
			if(!ff){
				break;
			}
		}
	}
		int tot=m;
		for(int i=1;i<=m;i++){
			d[i]=a[i];
		}
		long long cnt=0;
		for(auto i:use){
				cnt+=c[i];
				for(int j=1;j<=n;j++){
					d[++tot]={n+use.size()+1,j,b[j][i]};
				}
		}
		for(int i=1;i<=n+use.size();i++){
			f[i]=i;
		}
		sort(d+1,d+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			int u=find(d[i].u);
			int v=find(d[i].v);
			if(u!=v){
				f[max(u,v)]=min(u,v);
				cnt+=d[i].w;
			}
		}
	res=min(res,cnt);
	cout<<res<<endl;
	return 0;
}
//7 7 8
//1 3 7
//3 4 9
//2 5 4
//2 7 5
//1 2 2
//1 6 10
