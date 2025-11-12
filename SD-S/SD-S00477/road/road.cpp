#include<iostream>
using namespace std;
int n,m,k,x[10010],y[10010],num;
int dp[10010][10010];
int a[10010][10010],b[12];
int main(){
  freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	cin>>x[i]>>y[i];
	cin>>dp[x[i]][y[i]]; 
	dp[y[i]][x[i]]=dp[x[i]][y[i]];
}
for(int i=1;i<=k;i++){
	cin>>b[i];
	for(int j=1;j<=m;j++){
	cin>>a[i][j]; 
}
}//
for(int i=1;i<=k;i++){
	for(int j=1;j<=m;j++){
		dp[x[j]][y[j]]=min(dp[x[j]][y[j]],b[i]+a[i][x[j]]+a[i][y[j]]);
		dp[y[i]][x[i]]=min(dp[y[j]][x[j]],b[i]+a[i][x[j]]+a[i][y[j]]);
		//if(a[i][y[j]]+a[i][x[j]]+b[i]<dp[x[i]][y[i]]) dp[x[i]][y[i]]=a[i][y[j]]+a[i];
}
}
for(int i=1;i<=m;i++){
	for(int j=1;j<=m;j++){
	num+=dp[i][j];
	
   }
}

cout<<num/2-6;
	return 0;
}
