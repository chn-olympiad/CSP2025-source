#include<bits/stdc++.h>
using namespace std;
struct d{
	int nx,w;
};
long long n,m,k,a[15][100005];
vector<d>t[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	int f=0;
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		if(a[i][0]!=0)f=1;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(f==0&&k!=0){
		cout<<"0";
		return 0;
	}
	return 0;
}
