#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e4+7;
#define show(x) cout<<#x<<" = "<<x<<"\n"
#define Show(x) cout<<#x<<" = "<<x<<" "
/*
最小生成树
*/ 
int n, m, k;
int fa[N];
struct node{
	int u, v, w;
};
bool cmp(node a, node b){
	return a.w<b.w;
}
//原图最小生成树
int val1;
//+
//虚点 
int val2;
vector<node> edge;
int vil[15];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
int edgeofvoidP[N];
signed main(){
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) edgeofvoidP[i]=INT_MAX;
	int voidP=n+1;
	for(int i=0;i<=n+1;i++) fa[i]=i;
	for(int i=1, u, v, w;i<=m;i++){
		cin>>u>>v>>w;
		edge.push_back({u, v, w});
	}
	sort(edge.begin(), edge.end(), cmp);
	for(node e:edge){
		int u=e.u, v=e.v, w=e.w;
		int ffu=find(u), ffv=find(v);
		if(ffu==ffv) continue;
		fa[ffu]=ffv;
		val1+=w;
	}
	if(k==0){
		cout<<val1<<"\n";
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>vil[i];
		for(int j=1;j<=n;j++){
			int W;
			cin>>W;
			edgeofvoidP[j]=min(edgeofvoidP[j], W);
		}
	}
	for(int i=1;i<=n;i++){
		edge.push_back({voidP, i, edgeofvoidP[i]});
	}
	sort(edge.begin(), edge.end(), cmp);
	for(int i=1;i<=n+1;i++) fa[i]=i;
	for(node e:edge){
		int u=e.u, v=e.v, w=e.w;
		int ffu=find(u), ffv=find(v);
		if(ffu==ffv) continue;
		fa[ffu]=ffv;
		val2+=w;
	}
	cout<<min(val1, val2)<<"\n";
	return 0;
}
/*
拼部分分 ！
高达 48pts! 
*/
