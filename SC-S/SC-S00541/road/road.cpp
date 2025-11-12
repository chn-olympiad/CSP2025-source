#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll,pair<int,int>>
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x;
}
struct node{
	int to;
	ll w;
};
int n,m,k;
vector<node>g[10015];
bool cnt[15],v[10015];
ll c[15];
int cc[15];
priority_queue<pli,vector<pli>,greater<pli>>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int w;
			w=read();
			g[n+i].push_back({j,w});
			g[j].push_back({n+i,w+c[i]});
		}
	}
	v[1]=1;
	for(auto [y,w]:g[1]){
		q.push({w,{1,y}});
	}
	ll ans=0;
	while(!q.empty()){
		auto [w,p]=q.top();
		int x=p.first;
		int y=p.second;
		q.pop();
		if(v[y])continue;
		v[y]=1;
		if(x>n)cnt[x-n]=1;
		if(y>n)cc[y-n]=w;
		ans+=w;
		for(auto [to,d]:g[y]){
			if(v[to])continue;
			q.push({d,{y,to}});
		}
	}
	for(int i=1;i<=k;i++){
		if(cnt[i]==0){
			ans-=cc[i];
		}
	}
	cout<<ans;
	return 0;
}