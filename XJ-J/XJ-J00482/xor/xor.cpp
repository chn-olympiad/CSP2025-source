#include<bits/stdc++.h>
using namespace std;
int a[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j,k,n,sum=0;
	cin>>n>>k;
	if(k==1)
	{
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
			{
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	if(k==0)
	{
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
			{
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	if(k!=0&&k!=1)
	{
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==k)
			{
				sum++;
			}
		}
	
		cout<<sum;
		return 0;
	}
	
	return 0;
} 


