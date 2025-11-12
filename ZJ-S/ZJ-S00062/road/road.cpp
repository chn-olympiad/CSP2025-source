#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10,M=1e6+10,N2=1e3+10;
int n,m,k;
ll c[20][N],g[N2][N2];
int fa[N];
struct Edge{
	int u,v;
	ll w;
	bool operator<(const Edge x)const{
		return w<x.w;
	}
}a[M];
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
void sol1(){
	for(int i=1;i<=m;++i) {
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=k;++i){
		for(int j=0;j<=n;++j) {
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=m;++i) {
		if(cnt==n-1)break;
		if(find(a[i].u)==find(a[i].v)) continue;
		cnt++;
		fa[find(a[i].u)]=find(a[i].v);
		ans+=a[i].w;
	}
	cout<<ans<<"\n";
}
vector<Edge>e;
void sol(){
	//find minimun gen_tree
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) g[i][j]=INT_MAX;
	for(int i=1;i<=m;++i){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	for(int i=1;i<=k;++i){
		for(int j=0;j<=n;++j) {
			cin>>c[i][j];
		}
	}
	long long ans=0;
	for(int j=1;j<=k;++j){
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				if(u==v)continue;
				g[u][v]=g[v][u]=min(g[u][v],c[j][u]+c[j][v]);
			}
		}
	}
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j) if(g[i][j]!=INT_MAX) e.push_back({i,j,g[i][j]});
	sort(e.begin(),e.end());
	int cnt=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=0;i<e.size();++i) {
		if(cnt==n-1)break;
		if(find(e[i].u)==find(e[i].v)) continue;
		cnt++;
		fa[find(e[i].u)]=find(e[i].v);
		ans+=e[i].w;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		sol1();
		return 0;
	}
	sol();
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//const int N=1e4+10,M=1e6+10,N2=1e3+10;
//int n,m,k;
//ll c[20][N],g[N2][N2],g_[N2][N2];
//int fa[N];
//struct Edge{
//	int u,v;
//	ll w;
//	bool operator<(const Edge x)const{
//		return w<x.w;
//	}
//}a[M];
//int find(int x){
//	return fa[x]=(fa[x]==x?x:find(fa[x]));
//}
//void sol1(){
//	
//}
//void init(){
//	cin>>n>>m>>k;
//	if(n<=1002){
//		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j) g[i][j]=g[j][i]=INT_MAX;
//	}
//	for(int i=1;i<=m;++i) {
//		cin>>a[i].u>>a[i].v>>a[i].w;
//		if(n<=1002){
//			g[a[i].u][a[i].v]=a[i].w;
//			g[a[i].v][a[i].u]=a[i].w;
//		}
//	}
//	sort(a+1,a+1+m);
//	for(int i=1;i<=k;++i){
//		for(int j=0;j<=n;++j) {
//			cin>>c[i][j];
//		}
//	}
//}
//vector<Edge>e;
//void sol(){
//	//find minimun gen_tree
//	for(int i=1;i<=n;++i) fa[i]=i;
//	int cnt=0;
//	ll ans=0;
//	vector<Edge>chs;//already choose which edges
//	for(int i=1;i<=m;++i) {
//		if(cnt==n-1)break;
//		if(find(a[i].u)==find(a[i].v)) continue;
//		cnt++;
//		fa[find(a[i].u)]=find(a[i].v);
//		ans+=a[i].w;
//		chs.push_back(a[i]);
//	}
//	if(k==0){
//		cout<<ans<<"\n";
//		return ;
//	}
//	//	//choose kth to update,and minimize the answer;
//	long long Ans=INT_MAX;
//	for(int i=1;i<(1<<k);++i){
//		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) g_[i][j]=INT_MAX;
//		long long tmp=0;
//		for(int j=1;j<=k;++j){
//			if((1<<(j-1))&i) {
//				tmp+=c[j][0];
//				for(int u=1;u<=n;++u){
//					for(int v=1;v<=n;++v){
//						if(u==v)continue;
//						g_[u][v]=g_[v][u]=min(min(g[u][v],c[j][u]+c[j][v]),g_[u][v]);
//					}
//				}
//			}
//		}
//		for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j){
//			if(g_[i][j]!=INT_MAX) e.push_back({i,j,g_[i][j]});
//		}
//		sort(e.begin(),e.end());
//		ans=0;
//		for(int i=1;i<=n;++i) fa[i]=i;
//		for(int i=0;i<e.size();++i) {
//			if(cnt==n-1)break;
//			if(find(e[i].u)==find(e[i].v)) continue;
//			cnt++;
//			fa[find(e[i].u)]=find(e[i].v);
//			tmp+=a[i].w;
//			chs.push_back(e[i]);
//		}
//		Ans=min(tmp,Ans);
//	}
//	cout<<Ans<<"\n";
//}
//int main(){
//	freopen("road1.in","r",stdin);
////	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0);
//	init();
//	sol();
//	return 0;
//}
