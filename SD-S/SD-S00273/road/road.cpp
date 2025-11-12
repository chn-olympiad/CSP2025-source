#include <bits/stdc++.h>
#include <vector>
#define w first
#define id second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef pair<int ,int> PII;
const int N=1e6+5;
const ll M=0x3f3f3f3f3f3f3f3f;
struct node {
	int x,y,w;
};
int n,m,k;
int fa[N];
vector <node> e;
ll a[N],c[N];
bool vis[N];
inline ll find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
inline bool cmp(node a,node b){
	return a.w<b.w;
}
ll K(){
	ll res=0;
	int tot=0;
	sort(e.begin(),e.end(),cmp);
	for(auto u:e){
		int a=find(u.x),b=find(u.y);
		if(a!=b){
			fa[b]=a;
			res+=u.w;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e.push_back({i,j,w});
		}
	}
	cout<<K();
	return 0;
}
