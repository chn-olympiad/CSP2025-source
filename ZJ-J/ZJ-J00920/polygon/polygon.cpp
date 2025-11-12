#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005],f[5005];
long long sum;
long long p(int x)
{
	if(x==0) return 1;	
	long long m=p(x/2)%mod;
	if(x%2==0)
	{
		return m*m%mod;
	}
	else
	{
		return m*m*2%mod;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	cin>>n;	
	freopen("polygon.out","w",stdout);	
	for(int i=1;i<=n;i++)
	{            
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int j=2;j<i;j++)
		{
			int l=1,r=j-1,mid,t=a[i]-a[j];
			while(l<r)
			{
				mid=(l+r)/2;
				if(a[mid]>=t)
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}	
			if(a[l]+a[j]==a[i])
			{
				sum=(sum+p(j-1)-p(l-2)-1)%mod;
			}
			else if(a[l]+a[j]>a[i])
			{
				sum=(sum+p(j-1)-p(l-2))%mod;
			}							
			cout<<l<<" "<<j<<" "<<i<<" "<<sum<<endl;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}