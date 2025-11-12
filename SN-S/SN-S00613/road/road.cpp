#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,vis[10001],dis[10001],c[11][10010],vs[10001],ans;
vector<pair<long long,long long> >g[10001];
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}return ans*f;
}

void D(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	priority_queue<pair<long long,long long> >pq;
	pq.push({s,0});
	while(pq.size()){
		u=pq.top().first;pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto& q:g[u]){
			int v=q.first,w=q.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				ans+=w;
				}
			}
		}
	}

int main(){
	n=read(),m=read(),k=read();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m;++i){
		u=read(),v=read(),w=read();
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j){
			c[i][j]=read();
		}
	}D(1);
	cout<<ans;
	return 0;
}

