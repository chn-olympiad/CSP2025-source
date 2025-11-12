#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int sum,n,a[1000010],f[1000010];
int ksm(int a,int b){
	if(b==0) return 1;
	if(b==1) return a%mod;
	int x=ksm(a,b/2)%mod;
	if(b%2==0) return x%mod*x%mod;
	else return a%mod*x%mod*x%mod;
}
void dfs(int x){
	if(x==n+1){
		int x=0,ans=0;
		for(int i=1;i<=n;i++)
			if(f[i]==1)
				x++,ans+=a[i];
		if(x<3) return ;
		for(int i=1;i<=n;i++)
			if(f[i]==1&&ans-a[i]<=a[i])
				return ;
		sum++;
		return ;
	}
	f[x]=1;dfs(x+1);
	f[x]=0;dfs(x+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=1){
			dfs(1);
			cout<<sum%mod;return 0;
		}
	int x=ksm(2,n);
	x=x-n-n*(n-1)/2-1;
	while(x<0){
		x+=mod;
	}
	cout<<x;
	return 0;
}
