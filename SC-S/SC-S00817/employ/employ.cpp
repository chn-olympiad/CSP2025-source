#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],cnt,f[505][505];
string s;
int dp(int i,int j){
	if(i==n || j==m){
		return f[i][j];
	}
	if(f[i][j]){
		return f[i][j];
	}
	int nn=dp(i+1,j);
	if(a[i]<j){
		nn=max(nn,dp(i+1,j+1)+1);
	}
	f[i][j]=nn;
	return f[i][j];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	cout<<dp(0,0);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}