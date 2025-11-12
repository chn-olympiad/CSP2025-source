#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[50005];
void dfs(int s,int l,int p,int m,int x){
	if(p==l+1){
		if(m>2*x)ans++;
		return ;
	}else{
		for(int i=s+1;i+l-p<=n;i++){
			dfs(i,l,p+1,m+a[i],max(x,a[i]));
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=3;k<=n;k++)for(int i=1;i+k-1<=n;i++)dfs(i,k,2,a[i],a[i]);
	cout<<ans;
	return 0;
}

