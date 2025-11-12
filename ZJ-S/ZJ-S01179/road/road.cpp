#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int v,q;
	bool is;
};
vector<aaa> a[10005];
int b[12][10005];
int c[12];
bool vis[10005]{0};
bool cmp(aaa a,aaa b){
	return a.q<b.q;
}
int d[10005];
int main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	long long ans=0;
	for(int i=1;i<=m;i++){
		int u,v,q;
		cin>>u>>v>>q;
		a[u].push_back({v,q,1});
		a[v].push_back({u,q,1});
		ans+=q;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<ans;
	return 0;
}
