#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,t,a[500];
long long ans;
void dfs(int x,int y,int z,int k){
	 if(x==n){
	 	if(k+1>=3&&(y+a[x])>(max(z,a[x])*2)) ans++;
	 	if(k>=3&&y>2*z) ans++;
	 	ans%=998244353;
	 	return;
	 }
	 dfs(x+1,y+a[x],max(z,a[x]),k+1);
	 dfs(x+1,y,z,k);
	 return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	printf("%ld",ans);
	return 0;
}
