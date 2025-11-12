#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s0=0,s1=0,ans=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
  		scanf("%d",&a[i]);
		if(a[i]==0)
			s0++;
		else if(a[i]==1)
			s1++;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else if(a[i]==1)
			{
				if(a[i+1]==1)
				{
					ans++;
					i++;
				}
			}
		}
	}
	else if(k==1)
		ans=s1;
	printf("%lld",ans);
	return 0;
}