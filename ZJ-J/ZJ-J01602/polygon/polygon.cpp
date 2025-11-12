#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long mod=998244353;
int n,a[5005],cnt[5005],sum;
void dfs(int s,int l,int num){
	if(s==1){
		for(int i=l;i<=n;i++)
		if(num>a[i])sum++,sum=sum%mod;
		return;
	}
	for(int i=l;i<=n-s+1;i++)
	{
		dfs(s-1,i+1,num+a[i]);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)flag=0;
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(n<3)printf("0");
		else{
			if(a[3]<a[2]+a[1])
			printf("1");
			else
			printf("0");
		}
		return 0;
	}
	if(n<=10){
		
		for(int i=3;i<=n;i++){
		    dfs(i,1,0);	
		}
		printf("%lld",sum%mod);
		return 0;
	}
	if(flag){
		int sum=0,ans;
		for(int i=3;i<=n;i++)
		{
			ans=1;
			for(int j=1;j<=i;j++)
			{
				ans=(ans+j*(n-i-j+2))%mod;
			}
			sum=(sum+ans)%mod;
		}
		printf("%lld",sum%mod);
		return 0;
	}
	return 0;
}
