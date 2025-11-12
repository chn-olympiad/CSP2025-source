
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+12;
int a[N],used[N];
int n,k,tot,ans;
bool solve(int mi)
{
	int infm=0;
	int m=0;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k)
			{
				if(j==i)
				{
					infm++;
					sum=0;
					continue;
				}
				m++;
				sum=0;
			}
		}
		if(m+infm>=mi)
		{
			return true;
		}
		else
		{
			m=0;
			sum=0;
		}
	}
	return false;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=0,r=n,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(solve(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
 } 
