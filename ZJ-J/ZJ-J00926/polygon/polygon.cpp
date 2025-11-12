#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long a[50005],n,k,ans,xr=1;
void dfs(int x,long long sum,int num,long long maxs){
	if(x>n){
		if(num>=3&&sum>2*maxs)ans=(ans+1)%p;
		return;
	}
	dfs(x+1,sum,num,maxs);
	maxs=max(maxs,a[x]);
	dfs(x+1,sum+a[x],num+1,maxs);	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1){
		for(int j=1;j<=n;j++)xr=(xr*2)%p;
		cout<<(xr-((((n*n)%p+n)/2)%p)-1)%p;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
