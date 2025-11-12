#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int root[10010];
int ans=0;
struct Edge{
	int to,wei;
};
vector<Edge>a[10010];
struct edge{
	int from,to,wei;
};
vector<edge>b;
bool cmp(edge p,edge q){
	return p.wei<q.wei;
}
int find(int x){
	int nx=x;
	while(x!=root[x]){
		x=root[x];
		root[nx]=x;
		nx=x;
	}return x;
}
int krus(){
	ans=0;
	int cnt=0;
	for(int i=0;i<b.size();i++){
		
		if(find(b[i].from)!=find(b[i].to)){
			root[b[i].from]=b[i].to;
			ans+=b[i].wei;
			cnt++;
		}if(cnt==n-1)return ans;
	}return -1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=1;i<=n;i++)root[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
		b.push_back({u,v,w});
	}
	sort(b.begin(),b.end(),cmp);
	krus();
	cout <<ans;
	return 0;
}
