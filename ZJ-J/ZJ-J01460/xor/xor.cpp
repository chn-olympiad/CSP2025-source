#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define R register
#define LL long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],t,ans,s[N],in[N],dis[N];
vector<int>g[N];
queue<int>q;
struct Node{
	int a,b;
}p[N];
inline void topo(){
	for(R int i=1;i<=t;i++) dis[i]=1;
	for(R int i=1;i<=t;i++)
		if(!in[i])
			q.push(i);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(R int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(in[v]){
				in[v]--;
				dis[v]=max(dis[v],dis[u]+1);
				if(!in[v]) q.push(v);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(R int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	for(R int i=1;i<=n;i++){
		for(R int j=i;j<=n;j++){
			int d=s[j]^s[i-1];
			if(d==k) p[++t]={i,j};
		}
	}
	for(R int i=1;i<=t;i++)
		for(R int j=i+1;j<=t;j++){
			int x=p[i].a,y=p[j].a,u=p[i].b,v=p[j].b;
			bool f=1;
			if(x>y) swap(x,y),swap(u,v),f=0;
			if(y<=u) continue;
			if(f) g[i].push_back(j),in[j]++;
			else g[j].push_back(i),in[i]++;
		}
	topo();
	for(R int i=1;i<=t;i++) ans=max(ans,dis[i]);
	cout<<ans<<'\n';
	return 0;
}
