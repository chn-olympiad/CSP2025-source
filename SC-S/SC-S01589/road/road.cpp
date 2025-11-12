#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e4+20,INF=0x3f3f3f3f3f3f3f3f;
int n,m,k;
vector<pair<int,int>>g[N]; 
int dis[N],vis[N];
int isr[N],c[N];
int ans,anss=INF;
template<typename T>inline void read(T &x){
	T ans=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()){
	}
	for(;isdigit(c);c=getchar()){
		ans=(ans<<1)+(ans<<3)+(c^'0');
	}
	x=ans;
	return;
}
template<typename T>inline void write(T x){
	if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
}
void prim(int x){
	for(int i=1;i<=n+k;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	dis[x]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,x});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
//		cout<<u<<' ';
		for(auto v:g[u]){
			if(isr[v.first]){
				continue;
			}
			if(v.second<dis[v.first]){
				dis[v.first]=v.second;
				q.push({dis[v.first],v.first});
			}
		}
		ans+=dis[u];
	}
//	cout<<endl;
	return;
}
void dfs(int x,int sum){
	if(x==k+1){
		ans=0;
		prim(1);
//		cout<<ans<<' '<<sum<<endl;
		anss=min(anss,ans+sum);
		return;
	}
	dfs(x+1,sum+c[x]);
	isr[x+n]=1;
	dfs(x+1,sum);
	isr[x+n]=0;
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u);
		read(v);
		read(w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			int a;
			read(a); 
			g[n+i].push_back({j,a});
			g[j].push_back({i+n,a});
		}
	}
	dfs(1,0);
	write(anss);
	return 0;
}