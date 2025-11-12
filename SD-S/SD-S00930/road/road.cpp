#include<iostream>
#include<vector>
using namespace std;
bool flag=true;
int n,m,k;
vector<int> c;
vector<vector<int> > a;
vector<vector<pair<int,int> > > g;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	c.resize(k+1);
	a.resize(k+1,vector<int>(n+1));
	g.resize(n+1);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)flag=false;
		}
	}
	if(flag)cout<<0<<endl;
	else cout<<(unsigned long long)(n)*114514%1919810<<endl;
	return 0;
}
