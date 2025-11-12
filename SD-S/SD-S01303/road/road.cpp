#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1000000+10;

	int n,m,k,cnt,ans;
	int ui[MAXN],vi[MAXN],wi[MAXN];
	int c[11];
	int veg[11][10000+20];
	int f[10000+20];

struct Edge{int u,v,w;};
vector<Edge>g;
void init(){
	for(int i=1;i<=n;i++)f[i]=i;
}
int find(int x){
	return x==f[x]?x:x=find(f[x]);
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
void kruskal(){
	int cnt=0;
	int res=0;
	sort(g.begin(),g.end(),cmp);
//	for(int i=0;i<g.size();i++)cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
	for(int i=0;i<g.size();i++){
		if(cnt==n-1)break;
		int x=find(g[i].u),y=find(g[i].v);
		if(x!=y){
			cnt++;
//			cout<<g[i].u<<" "<<g[i].v<<endl;
			f[x]=y;
			res+=g[i].w;
		}
	}
	ans=res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ui[i]>>vi[i]>>wi[i];
		g.push_back({ui[i],vi[i],wi[i]});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
		for(int j=1;j<=n;j++){
			cin>>veg[i][j];
			for(int o=1;o<=j;o++)g.push_back({o,j,c[i]+veg[i][o]+veg[i][j]});
		}
	}
	init();
	kruskal();
	cout<<ans;
	return 0;
}
