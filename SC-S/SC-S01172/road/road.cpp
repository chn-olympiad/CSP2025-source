#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
int n,m,k,sum,w[15];vector<pii>t[10010],f[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		sum+=z;
		t[x].push_back({y,z});
		t[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		cin>>w[i];
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			f[x].push_back(y,z);
		}
	}
	cout<<sum;
	return 0;
}
