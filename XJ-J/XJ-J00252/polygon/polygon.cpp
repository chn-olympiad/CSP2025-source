#include<bits/stdc++.h>
using namespace std;
int a[5012],vis[5012],ans,n,dp[5201];
void dfs(int sum,int he,int xia){
	for(int i=xia+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			//cout<<i<<" ";
			dfs(sum+1,he+a[i],i);
			//cout<<he<<endl;
			vis[i]=0;
			if(sum>=3){
				if(he>a[i]){
					ans++;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}//5 1 2 3 4 5

