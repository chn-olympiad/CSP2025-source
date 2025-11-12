#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f[15][15],x;
void dfs(int x,int y,int k){
	f[x][y]=a[k];
	if(k==n*m)return;
	if(y%2==1){
		if(x<n)dfs(x+1,y,k+1);
		if(x==n)dfs(x,y+1,k+1);
	}
	else if(y%2==0){
		if(x>1)dfs(x-1,y,k+1);
		if(x==1)dfs(x,y+1,k+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	dfs(1,1,1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(f[i][j]==x){
		cout<<j<<" "<<i;
		return 0;
	}
}
