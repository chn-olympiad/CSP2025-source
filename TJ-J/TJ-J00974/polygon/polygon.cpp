#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
int a[5005];
void dfs(int lev,int num,int sum){
	if(lev==n+1) return;
	ans+=sum*(n-num);
	for(int i=num+1;i<=n;i++){
		dfs(lev+1,i,sum*(n-num));
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int maxx=max(a[1],max(a[2],a[3]));
		if(sum>2*maxx) cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}
