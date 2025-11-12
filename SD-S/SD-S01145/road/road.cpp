#include<bits/stdc++.h>
using namespace std;
struct A{
	int v,w;
	bool o;
	int fa;
};
int c[100010],n,m,k;
bool vis[100010];
bool cvis[100010];
int x[100010];
struct B{
	int x;
	long long s;
	int o,f,y;
	bool operator <(const B y)const{
		return s>y.s;
	}
};
vector<A> g[100010];
long long ans=0;
void dj(){
	priority_queue<B> q;
	q.push({1,0,0,0,0});
	while(!q.empty()){
		B t=q.top();
		q.pop();
		if(vis[t.x]==1) continue;
		vis[t.x]=1;
		if(cvis[t.f]==1&&t.y==1) continue;
		if(t.o==1){
			cvis[t.f]=1;
		}
		ans+=t.s;
		for(auto y:g[t.x]){
			if(vis[y.v]==1) continue;
			long long st=0;
			int oo=0;
			int ye=0;
			int ff=0;
			if(y.o==0){
				st+=y.w;
			}else{
				oo=1;
				ff=y.fa;
				if(cvis[y.fa]==0){
					ye=1;
					st+=y.w;
					st+=c[y.fa];
				}else{
					st+=y.w;
				}
			}
			q.push({y.v,st,oo,ff,ye});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w,0,0});
		g[v].push_back({u,w,0,0});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=1;j<n;j++){
			for(int o=j+1;o<=n;o++){
				g[j].push_back({o,x[j]+x[o],1,i});
				g[o].push_back({j,x[j]+x[o],1,i});
			}
		}
	}
	dj();
	cout<<ans;
	return 0;
}

