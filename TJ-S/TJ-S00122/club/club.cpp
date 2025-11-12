#include"bits/stdc++.h"
using namespace std;
int a[100010][10],t,n,ans;
void dfs(int s,int m,int x,int y,int z){
	if(m==n){
		ans=max(ans,s);
		return;
	}
	if(x<n/2) dfs(s+a[m][0],m+1,x+1,y,z);
	if(y<n/2) dfs(s+a[m][1],m+1,x,y+1,z);
	if(z<n/2) dfs(s+a[m][2],m+1,x,y,z+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
