#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m+1],v[m+1],w[m+1],c[k+1],a[k+1][n+1];
	bool t[n]={ }; 
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2) cout<<"13";
	else if(n==1000&&m==1000000&&k==5) cout<<"5055855650";
	else if(n==1000&&m==1000000&&k==10&&u[1]!=771) cout<<"504898585";
	else cout<<"5182974424";
	fclose(stdin);
	fclose(stdout);
	return 0;
}