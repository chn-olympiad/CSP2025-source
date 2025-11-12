#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;

const int N=1e4+5,M=1e6+5;

struct edge{
	int u,v,w;
	bool operator<(const edge& t)const{
		return w<t.w;
	}
}e[M];
vector<int>e2[N];

int sum[N],fa[N],c[20][N],vis[N];
int n,m,k;
ull ans=1e18;

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int kruscal(){
	int s=0;
	sort(e+1,e+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<n;i++){
		int v=e[i].v,u=e[i].u,w=e[i].w;
		int x=find(fa[u]);
		int y=find(fa[v]);
		if(x!=y){
			sum[u]+=w;
			sum[v]+=w;
			e2[u].push_back(v);
			e2[v].push_back(u);
			s+=w;
			fa[x]=y;
		}
	}
	return s;
}

/*int prim(){
	int s=0;
	priority_queue<pair<int,int>>q;
	memset(d,0x3f3f3f3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	q.push({0,1});
	//d[1]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		s+=d[u];
		cout<<u<<":"<<d[u]<<endl;
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(d[v]>w){
				d[v]=w;
				q.push({-d[v],v});
			}
		}
	}
	return s;
}*/

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
 	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			scanf("%d",&c[i][j]);
	ull t=kruscal();
	//cout<<t<<endl;
	//for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	for(int i=1;i<=k;i++){
		ull res=t+c[i][0];
		for(int j=1;j<=n;j++){
			res-=sum[j];
			res+=c[i][j];
			if(res>=t) continue;
			vis[j]=1;
			for(int v:e2[j]){
				res+=c[i][v];
				vis[v]=1;
			}
			int b=1e9;
			for(int v=1;v<=n;v++){
				if(vis[v]){
					vis[v]=0;
					continue;
				}
				b=min(c[i][v],b);
			}
			res+=b;
		}
		ans=min(ans,res);
	}
	ans=min(ans,t);
	printf("%dll",ans);
	//cout<<0;
 	fclose(stdin);
    fclose(stdout);
    return 0;
}

