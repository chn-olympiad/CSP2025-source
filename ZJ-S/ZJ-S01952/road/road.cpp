#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct nn{
	int fr;
	int to;
	int val;
};
vector<nn> gr[N];
int town[21][N],fa[N];
bool vis[N];
struct nngreater{
	operator()(const nn& a,const nn& b){
		return a.val>b.val;
	}
};
int Fa(int f){
	return fa[f]==f?f:fa[f]=Fa(fa[f]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	priority_queue<nn,vector<nn>,nngreater> qu;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,val;
		cin>>x>>y>>val;
		gr[x].push_back({val,y});
		qu.push({x,y,val});
	}for(int i=1;i<=k;i++){
		cin>>town[i][0];
		for(int j=1;j<=n;j++){
			cin>>town[i][j];
		}
	}for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int ans=0;
	while(!qu.empty()){//zui xiao sheng cheng shu
		nn u=qu.top();qu.pop();
		if(vis[u.to]) continue;
		vis[u.to]=true;
		int fx=Fa(u.fr),fy=Fa(u.to);
		if(fx!=fy){
			fa[u.fr]=u.to;
//			cerr<<u.fr<<" "<<u.to<<"\n";
			ans+=u.val;
		}
	}
	cout<<ans;
	return 0;
}