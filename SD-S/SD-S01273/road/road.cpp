#include<bits/stdc++.h>
#define int long long
using namespace std;
//UID:1137851
//ANGRY
const int N=1e4+5;
int T;
int n,m,k;
struct edge{
	int u,v,w;
	bool operator < (const edge &b) const{
		return w>b.w;
	}
};
vector <edge> mp;
priority_queue <edge> owo;
vector <edge> qwq[N];
int c[N];
int ans=1e18;
int sum;
int color[N];
vector <int> col[N];
void solve(){
	while(!owo.empty()){
		edge ow=owo.top();
		owo.pop();
		if(color[ow.u]!=color[ow.v]){
			sum+=ow.w;
			int cc=color[ow.u];
			while(col[cc].size()>0){
				int i=col[cc].back();
				col[color[ow.v]].push_back(i); 
				color[i]=color[ow.v];
				col[cc].pop_back();
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	edge d;
	for(int i=1;i<=m;i++){
		cin>>d.u>>d.v>>d.w;
		mp.push_back(d);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		d.u=n+1;
		for(int j=1;j<=n;j++){
			cin>>d.w;
			d.v=j;
			qwq[i].push_back(d);
		}
	}
	for(int i=0;i<=k;i++){
		for(auto j:mp) owo.push(j);
		for(auto j:qwq[i]) owo.push(j);
		for(int j=1;j<=n+1;j++){
			col[j].clear();
			color[j]=j;
			col[j].push_back(j);
		} 
	 sum=c[i];
		solve();
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

