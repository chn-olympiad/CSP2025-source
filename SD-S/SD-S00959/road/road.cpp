#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
vector<pair<int,int> >v[10005];
int c[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;ans+=z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<ans; 
	return 0;
}

