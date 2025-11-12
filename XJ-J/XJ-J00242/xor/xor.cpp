#include<bits/stdc++.h>
using namespace std;
long long int a[500005],flag[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k,i,j,x,y,q,num,ans=0,f;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(j-i>1)
			{
				num=a[i];
				for(x=i+1;x<=j;x++)
				{
					num=num+num|a[x];
				}
			}
			else
			{
				num=a[i]|a[j];
			}
			f=0;
			for(q=i;q<=j;q++)
			{
				if(flag[q]!=0)
				{
					f=1;
				}
			}
			if(num==k&&f==0)
			{
				ans++;
				for(y=i;y<=j;y++)
				{
					flag[y]++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
