#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int start,int num,int maxx,int sum){
	if(sum>maxx*2&&num>=3){
		ans++;
		ans=ans%998244353;
	}
	if(start==n){
		return;
	}
	for(int i=start+1;i<=n;i++){
		dfs(i,num+1,max(maxx,a[i]),sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		dfs(i,1,a[i],a[i]);
	}
	cout<<ans;
	return 0;
}
