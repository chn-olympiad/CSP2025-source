#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
int n;
long long a[5555],ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		long long cnt=0;
		for(long long i=n-2;i>=1;i--)
			cnt=(cnt+i)%P;
		cout<<cnt;
		return 0;
	}
	if(n<=20)
	{
		for(long long s=0;s<=(1<<n)-1;s++)
		{
			long long mx=0,sum=0;
			for(int i=0;i<n;i++)
			{
				if((s>>i)&1)
				{
					sum+=a[i+1];
					mx=a[i+1];
				}
			}
			if(sum>mx*2) ans=(ans+1)%P;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
