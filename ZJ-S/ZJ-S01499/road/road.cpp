#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=1e6+10;
long long a[30][N],c[30];
int f[N];
struct node{
	int u;
	int v;
	long long w;
};
bool cmp(node A,node B){
	return A.w<B.w;
}
int find(int id){
	return f[id]==id?id:f[id]=find(f[id]);
}
node b[M],p[N];
int n,m,k;
int t[30];
long long ans=1e18;
vector<node>e;
void check(){
	e.clear();
	for(int i=1;i<n;i++)e.push_back({p[i].u,p[i].v,p[i].w});
	long long cnt=0;
	for(int i=1;i<=k;i++)if(t[i]){
		cnt+=c[i];
		for(int j=1;j<=n;j++){
			e.push_back({n+i,j,a[i][j]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(node to:e){
		int fa=find(to.u);
		int fb=find(to.v);
		if(fa!=fb){
			f[fa]=fb;
			cnt+=to.w;
		}
	}
	ans=min(ans,cnt);
	return;
}
void dfs(int len){
	if(len==k+1){
		check();
		return;
	}
	t[len]=0;
	dfs(len+1);
	t[len]=1;
	dfs(len+1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//the solution must is a tree
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	sort(b+1,b+m+1,cmp); 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int id=1;
	for(int i=1;i<=m;i++){
		int fa=find(b[i].u);
		int fb=find(b[i].v);
		if(fa!=fb){
			f[fa]=fb;
			p[id].u=b[i].u;
			p[id].v=b[i].v;
			p[id].w=b[i].w;
			id++;
		}
	}
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}