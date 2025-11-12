#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long a[5005],cnt[5005],cnt2[5005],n,ans;
long long fun(long long x)
{
	long long sum=0;
	
	memset(cnt2,0,sizeof(cnt2));
	
	for(long long i=0;i<=5001;i++)
	cnt2[min(5001*1LL,i+a[x-1])]=(cnt2[min(5001*1LL,i+a[x-1])]+cnt[i])%N;
	
	for(long long i=0;i<=5001;i++)
	cnt[i]=(cnt[i]+cnt2[i])%N;
	
	for(long long i=a[x]+1;i<=5001;i++)
	sum=(sum+cnt[i])%N;
	return sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	cnt[0]=1;
	for(long long i=0;i<=5001;i++)
	cnt2[min(5001*1LL,i+a[1])]=(cnt2[min(5001*1LL,i+a[1])]+cnt[i])%N;
	for(long long i=0;i<=5001;i++)
	cnt[i]=(cnt[i]+cnt2[i])%N;
	for(long long i=3;i<=n;i++)
	{
	ans=(ans+fun(i))%N;
	}
	cout<<ans;
	return 0;
}
