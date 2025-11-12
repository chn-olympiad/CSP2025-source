#include<bits/stdc++.h>
#define int long long
#define MAXN 4000005
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int n,m,k,s=1;
int ans1=0,ans2=LLONG_MAX;

struct Edge{
	int to,val;
	bool operator < (Edge tmp) const{
		return val < tmp.val;
	} 
};

vector<Edge> edge[MAXN];
priority_queue<Edge> q;
int dis[MAXN],vis[MAXN],l[MAXN],c[MAXN];

void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	q.push({s,0});
	while(!q.empty()){
		Edge tmp=q.top();
		q.pop();
		int u=tmp.to;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:edge[u]){
			int v=e.to;
			int w=e.val;
			if(dis[v]+w<dis[u]){
				dis[u]=dis[v]+w;
				q.push({v,w});
			} 
		}
	}
	
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
		ans1+=w;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		int res=0;
		for(int j=1;j<=n;j++){
			l[j]=read();
			res+=l[j];
		}
		res*=2;
		res=res-l[1]-l[n];
		ans2=min(ans2,res);
	}
	for(int i=1;i<=k;i++){
		for(int j=2;j<=n;j++){
			edge[i].push_back({j,l[i]+l[j]});
			edge[j].push_back({i,l[i]+l[j]});
		}
	}
	dijkstra();
	int ans=0;
//	for(int i=1;i<=n;i++){
//		for(auto x:edge[i]){
//	//		ans+=x;
//			cout<<x.to<<" "<<x.val<<"\n";
//		}
//	}
	for(auto x:dis){
		ans+=x;
	}
//	cout<<ans<<"\n";
	printf("%lld\n",min(ans1,ans2));
	return 0;
}

