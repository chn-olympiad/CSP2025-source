#include <bits/stdc++.h>
using namespace std;
long long n,a[1005],sum,mx,ans,j,x[105];
void dfs(int t){
	if(t==0){
		if(sum>mx*2&&j>=3)ans=(ans+1)%998244353;
		return;
	}
	dfs(t-1);
	x[t]=mx;
	mx=max(mx,a[t]);
	sum+=a[t];
	j++;
	dfs(t-1);
	j--;
	mx=x[t];
	sum-=a[t];
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>25){
		long long t=1+n+(n-1)*n/2;
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*2%998244353;
		}
		cout<<(ans-t)%998244353;
		return 0;
	}
	dfs(n);
	cout<<ans%998244353;
	return 0;
}

