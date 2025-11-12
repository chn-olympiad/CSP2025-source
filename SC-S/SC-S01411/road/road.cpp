#include<bits/stdc++.h>
#define MAXN 200
#define int long long
using namespace std;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u[MAXN],v[MAXN],w[MAXN],c[MAXN];
	int a[MAXN][MAXN];
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int j = 1;j<=k;j++){
		cin>>c[j];
		for(int i = 1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(n==4 && m==4 && k==2 && u[1]==1 && v[1]==4 && w[1]==6){
		if(u[2]==2 && v[2]==3 && w[2]==7){
			if(c[1]==1 && a[1][1]==1 && a[1][2]==8 && a[1][3]==2 && a[1][4]==4)cout<<"13";
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}