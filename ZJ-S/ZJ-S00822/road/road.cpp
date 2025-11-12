#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v,w;
	bool operator< (const edge e) const{
		return w<e.w;
	}
};
vector<edge> ed;
int n,m,k,ans;
int fa[10015],c[11],a[11][10001],siz[10015];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(siz[x]<siz[y]){
		fa[x]=y;
		siz[y]+=siz[x];
	}
	else{
		fa[y]=x;
		siz[x]+=siz[y];
	}
}
int kruskal(int s,int ednum){
	vector<edge> ed2;
	for(auto e:ed){
		ed2.push_back(e);
	}
	sort(ed2.begin(),ed2.end());
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		siz[i]=1;
	}
	int ret=0;
	for(int i=0;i<ednum;i++){
		int u=ed2[i].u,v=ed2[i].v;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ret+=ed2[i].w;
	}
	return ret;
}
void dfs(int b,int sum,int edsum){
	if(b==k){
		ans=min(ans,sum+kruskal(1,edsum));
		return;
	}
	for(int i=1;i<=n;i++){
		ed.push_back((edge){b+n+1,i,a[b][i]});
	}
	dfs(b+1,sum+c[b],edsum+n);
	for(int i=1;i<=n;i++){
		ed.pop_back();
	}
	if(c[b]!=0) dfs(b+1,sum,edsum);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ed.push_back((edge){u,v,w});
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		if(c[i]==0){
			for(int j=1;j<=n;j++){
				ed.push_back((edge){i+n+1,j,a[i][j]});
			}
			m+=n;
		}
	}
	ans=1000000000000001ll;
	dfs(0,0,m);
	cout<<ans<<"\n";
	return 0;
}//72~64pts