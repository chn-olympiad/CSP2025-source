#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	int mmax=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
				mmax++;
		}
		int mmmax=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=a[i+1]&&b[i]!=123&&b[i+1]!=123)
			{
				mmmax++;
				b[i]=123;
				b[i+1]=123;
			}
		}
		cout<<max(mmax,mmmax);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				mmax++;
		}
		int mmmax=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1]&&b[i]!=123&&b[i+1]!=123)
			{
				mmmax++;
				b[i]=123;
				b[i+1]=123;
			}
		}
		cout<<max(mmax,mmmax);
	}
	return 0;
}
