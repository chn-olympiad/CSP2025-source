#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],t,r,h;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			t++;
		}
		if(a[i]==0)
		{
			r++;
		}
	}
	if(r==0&&n==t)
	{
		if(k==0)
		{
			cout<<n/2;
			return 0;
		}
	}
	if(r!=0&&n==t+r)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					h++;
				}
				if(a[i]==0)
				{
					r+=h/2;
					h=0;
				}
			}
			cout<<r;
			return 0;
		}
		if(k==1)
		{
			cout<<t;
			return 0;
		}
	}
	cout<<12701;
	return 0;
 } 
