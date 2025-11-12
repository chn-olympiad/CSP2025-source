#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e4+5, M=3e6+5;
int n,m,k;
int c[15],a[15][N];
int tot,head[N],to[M],val[M],nxt[M];
inline void adde(int u,int v,int w){
	++tot;
	to[tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}

ll Prim(){
	ll dis[N],ans=0;
	bool vis[N]={};
	typedef pair<ll,int> node;
	priority_queue<node,vector<node>,greater<node> > q;
	memset(dis,0x3f,sizeof dis);
	
	dis[1]=0;
	q.push({0,1});
	int cnt=0;
	while(cnt<n){
		node tmp=q.top();
		q.pop();
		int u=tmp.second;
		if(vis[u])continue;
		vis[u]=1;
		ans+=tmp.first;
		if(u<=n)++cnt;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=val[i];
			if(!vis[v]){
				//if(v>n)w+=c[v-n];
				if(dis[v]>w){
					dis[v]=w;
					q.push({dis[v],v});
				}
			}
		}
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);
		adde(v,u,w);
	}
	for(int i=1;i<=k;++i){
		scanf("%d",c+i);
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			adde(n+i,j,a[i][j]);
			adde(j,n+i,a[i][j]+c[i]);
		}
	}
	cout<<Prim();
	
	return 0;
}
