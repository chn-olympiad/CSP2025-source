#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long a[N],n,k,cnt1,cnt0;
bool fk,f0,f1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=k)
		{
			fk=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			f0=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			f1=1;
			break;
		}
	}
	if(fk==0)
	{
		cout<<n;
	}
	else if(f1==0)
	{
		if(k==0)
		{
			cout<<n/2;
		}
		else
		{
			cout<<n/2;
		}
	}
	else if(f0==0)
	{
		if(k!=0)
		{
			cout<<0;
		}
		else
		{
			cout<<n/2;
		}
	}
	else if(f0&&f1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt1++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt0++;
			}
		}
		if(k==1)
		{
			cout<<cnt1;
		}
		else if(k==0)
		{
			cout<<max((cnt0+(n-cnt0)/2),((cnt1/2)+cnt0));
		}
		else
		{
			cout<<n/2;
		}
	}
	else
	{
		cout<<n/2;
	}
	return 0;
}
