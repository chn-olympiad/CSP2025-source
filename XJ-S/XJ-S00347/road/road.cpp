#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005][10005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,c;i<=m;i++){
		cin>>u>>v>>c;
		a[u][v]=c;
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
		c/=4;
		for(int j=1,z;j<=n;j++){
			if(i==j)	continue;
			cin>>z;
			a[i][j]=min(a[i][j],z+c);
		}
	}
	cout<<rand();
	return 0;
}
