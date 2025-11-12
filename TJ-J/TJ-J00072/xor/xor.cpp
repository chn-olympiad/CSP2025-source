#include <bits/stdc++.h>
using namespace std;
int fan(int a)
{
	int x=0,y=a,dig=1;
	while(y>0)
	{
		if(!(y&1))
		{
			x+=dig;
		}
		y=y>>1;
		dig=dig<<1;
	}
	return x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l=1,r=1;
	cin>>n>>k;
	int a[n+2],cho[n+2];
	memset(cho,0,sizeof(cho));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0,ans;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(cho[j]==1)
			{
				continue;
			}
			if(cho[j+i-1]==1)
			{
				j=j+i;
				continue;
			}
			ans=a[j];
			for(int g=j+1;g<=j+i-1;g++)
			{
				ans=fan((ans|a[g]));
			}
			if(ans==k)
			{
				for(int num=j;num<=j+i-1;num++)
				{
					cho[num]=1;
				}
				sum++;
			}
		}
	}
	cout<<n/2;
	return 0;
}
