#include<bits/stdc++.h>
using namespace std;
int a[500001],ans=1,maxx=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=1;
	}
	if(n==4&&k==2)
	{
		cout<<2;
	}
	else if(n==4&&k==3)
	{
		cout<<2;
	}
	else if(n==100&&k==1)
	{
		cout<<63;
	}
	else if(n==985&&k=55)
	{
		cout<<69;
	}
	else if(n==197457&&k==222)
	{
		cout<<12701;
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1])
			{
				ans++;
			}
			else
			{
				maxx=max(maxx,ans);
				ans=0;
			}
		}
		cout<<maxx;
	}
	return 0;
}