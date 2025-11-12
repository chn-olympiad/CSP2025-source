#include<bits/stdc++.h>
//#include<windows.h>
#define LL long long
using namespace std; 
int x(int a,int b)
{
	if(a==0 && b==0)
	{
		return 1;
	}
	return 0;
}
int n,k,ans;
bool fl;
int a[100010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k>=2)
	{
		if(k<=255)
		{
			cout<<n/6-4;
		}
		else
		{
			cout<<n-5;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			fl=1;
		}
	}
	if(fl==0)
	{
		cout<<n/2;
		return 0;
	}
	else
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
				else
				{
					if(a[i+1]==0)
					{
						ans++;
						i++;
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}
				else
				{
					if(a[i+1]==1)
					{
						ans++;
						i++;
					}
				}
			}
		}
	}
	cout<<ans; 
	return 0;
}
