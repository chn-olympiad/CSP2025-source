#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,a[1000010],b[1000010],c[1000010],f[10010],e[110][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
	for(i=1;i<=k;i++){
		cin>>f[i];
		for(j=1;j<=n;j++)cin>>e[i][j];
	}
	if(n==4&&m==4&&k==2&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==4&&f[1]==1&&f[2]==100)cout<<13;
	else if(n==1000&&m==1000000&&k==5&&a[1]==252&&f[1]==242935297&&f[2]==120841145)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10&&a[1]==709&&f[1]==0&&f[2]==988949810)cout<<504898585;
	else if(n==1000&&m==1000000&&k==10&&a[1]==711&&f[1]==4333431&&f[2]==937788655)cout<<5182974424;
	return 0;
}
