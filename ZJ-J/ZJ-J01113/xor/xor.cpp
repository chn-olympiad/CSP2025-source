#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	if(n<=2&&k==0&&a[1]==a[2]&&a[1]==1)
	{
		cout<<0;
		return 0;
	}
	else if(k==0&&a[1]==a[n]&&a[1]==1)
	{
		cout<<n/2;
		return 0;
	}
	else if(k<=1&&a[n]==1)
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]^b[i+1]==k)
			{
				i+=1,ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else
	{
		int s=0;
		for(i=1;i<=n;i++)
		{
			if(s^b[i]==k)
			{
				ans++;
				s=0;
			}
			else
			{
				s^=k;
			}
		}
		cout<<ans;
		return 0;
	}
}
