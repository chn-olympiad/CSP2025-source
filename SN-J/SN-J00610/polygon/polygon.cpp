#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,dp[5005][5005],maxm;
void dfs(int sum,int maxm,int x,int v){ 
	if(x>n){
		return;
	}
	if(x>=3){
		if(sum>2*maxm&&sum!=v){
			ans=(ans%998244353)+1;
			v=sum;
		}
	}
	dfs(sum+a[x],max(maxm,a[x]),x+1,v);
	dfs(sum,maxm,x+1,v);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
