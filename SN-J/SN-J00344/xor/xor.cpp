#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
long long n,k,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(k==1)
	{
		long long x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				x++;
			}
			else
			{
				y++;
			}
		}
		cout<<max(x,y);
		return 0;
	}
	return 0;
}
