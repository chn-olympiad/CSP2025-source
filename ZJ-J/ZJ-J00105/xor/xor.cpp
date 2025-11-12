#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	if(n==1)
	{
		if(a[1]==k)
		{
			cout<<1<<endl;
			return 0;
		}
		else
		{
			cout<<0<<endl;
			return 0;
		}
	}
	if(n==2)
	{
		if(a[1]==k)
		{
			c++;
		}
		if(a[2]==k)
		{
			c++;
		}
		if((a[1]^a[2])==k)
		{
			c++;
		}
		cout<<c<<endl;
		return 0;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[j]-b[i]==k)
			{
				c++;
			}
		}
	}
	
	cout<<c<<endl;
	return 0;
}
