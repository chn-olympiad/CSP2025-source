#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int mx=1e4+10;

struct edge{
	int u,v;
	int w;
};
vector<edge> a;
int c[20];
int b[20][mx];
int ans=0;

bool cmp(edge x,edge y){
	return x.w<y.w;
}
int n,m,k;
int f[mx];

int get_fa(int u){
	if(f[u]==u) return u;
	return f[u]=get_fa(f[u]);
}
void combine(int u,int v){
	int fu=get_fa(u),fv=get_fa(v);
	if(fu==fv) return;
	f[fv]=fu;
}
void init(){
	for(int i=1;i<=n+k;i++) f[i]=i;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ans+=c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			a.push_back({n+i,j,b[i][j]});
		}
	}
	sort(a.begin(),a.end(),cmp);
	int cnt=0;
	for(int i=0;i<a.size();i++){
		int u=a[i].u,v=a[i].v;
		if(get_fa(u)!=get_fa(v)){
			cnt++;
			ans+=a[i].w;
			combine(u,v);
		}
		if(cnt==n+k-1) break;
	}
	cout<<ans<<endl;
	return 0;
}
