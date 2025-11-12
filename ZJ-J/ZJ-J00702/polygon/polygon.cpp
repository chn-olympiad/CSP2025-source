#include <bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,i,ans,a[5010],b[5010];
void dfs(long long t,long long fl,long long ma,long long sum,long long num){
	if(sum+b[t]<=ma*2) return ;
	if(t==n+1){
		if(sum>ma*2&&num>=3)
			ans=(ans+1)%Mod;
		return ;
	}
	else{
		if(fl==1) dfs(t+1,1,ma,sum+a[t],num+1);
		else dfs(t+1,1,a[t],sum+a[t],num+1);
		dfs(t+1,fl,ma,sum,num);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2){
		cout<<"0";
		return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	if(a[1]==1){
		ans=1;
		for(i=1;i<=n;i++)
			ans=ans*2%Mod;
		ans--;ans-=n;
		ans-=n*(n-1)/2;
		if(ans<0) ans+=Mod;
		cout<<ans;
		return 0;
	}
	b[n]=a[n];
	for(i=n-1;i>=1;i--)
		b[i]=b[i+1]+a[i];
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}
