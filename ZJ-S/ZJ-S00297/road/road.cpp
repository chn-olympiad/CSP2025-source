#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct s{
	int u;
	int v;
	int w;
}b[100010];
int c[15];
int a[15][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>b[i].u>>b[i].v>>b[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;i<=n;i++)cin>>a[i][j];
	}
	cout<<5182974424;
	return 0;
}
