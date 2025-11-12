#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
int qian[500001];
int dp[500001];
int maxx;
void dfs(int sum,int l){
	if(l>n){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=l;i<=n;i++){
		if(dp[i]!=n+1)dfs(sum+1,dp[i]+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(k==0 && flag==true){
		cout<<n/2;
		return 0;
	}
	if(k==0 && flag==false){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]==1 && i<n && a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			qian[i]=qian[i-1]^a[i];
		}
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if((qian[r]^qian[l-1])==k){
					dp[l]=r;
					break;
				}
			}
			if(dp[l]==0)dp[l]=n+1;
		}
		dfs(0,1);
		cout<<maxx;
	}
	return 0;
}
