#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0,sun=0,f=0;
	cin>>n>>k;
	int a[500005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			sum++;
		}
		if(a[i]==0)
		{
			sun++;
		}
	}
	if(k==0&&sum==n)
	{
		cout<<n/2;
		return 0;
	}
	else if(k==1&&sun==n)
	{
		cout<<"0";
		return 0;
	}
	else if((k==0&&sun==n)||(k==1&&sum==n))
	{
		cout<<n;
		return 0;
	}
	else if(k==0&&sum+sun==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1&&a[i+2]==0)
			{
				sun++;
			}
		}
		cout<<sun;
		return 0;
	}
	else if(k==1&&sum+sun==n)
	{
		cout<<sum;
		return 0;
	}
	return 0;
}
