#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7,maxm=1e4+7;
int n,m,k,c[maxm],a[maxm][maxm],fa[maxn],sum;
struct node{
	int u,v,w;
}edge[maxn];
struct Node{
	int v,w;
};
vector<Node> mp[maxn];
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void join(int a,int b){
	int u=find(a),v=find(b);
	if(u!=v) fa[u]=v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		mp[edge[i].u].push_back({edge[i].v,edge[i].w});
		mp[edge[i].v].push_back({edge[i].u,edge[i].w});
		sum+=edge[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		init(n);
		
	}
	cout<<sum;
	return 0;
}
