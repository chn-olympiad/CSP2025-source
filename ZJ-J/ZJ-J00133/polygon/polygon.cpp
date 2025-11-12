#include <bits/stdc++.h>
using namespace std;
int mx=-1,vis[5005],n,a[5005],ans;
int f(int k){
	long long ret=1;
	for(int i=n;i>=n-k+1;i--){
		ret*=i;
	}
	for(int i=1;i<=k;i++){
		ret/=i;
	}
	return ret;
}
void dfs(int deep,int k,int sum,int longest,int lastid){
	if(deep>k){
		if(sum>2*longest){
		ans++;
		ans=ans%998244353;
		return;
	}
	}
	for(int i=lastid+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
	    	dfs(deep+1,k,sum+a[i],max(longest,a[i]),i);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=3;i<=n;i++)
			ans+=f(i)%998244353;
		cout<<ans;
		return 0;
	}
	for(int k=3;k<=n;k++){
		dfs(1,k,0,0,0);
	}
	cout<<ans;
	return 0;
}
