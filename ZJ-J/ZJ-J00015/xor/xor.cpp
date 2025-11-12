#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long l,r;
}c[500100];
long long n,k,a[500100],b[500100],cnt,ans;
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i1=1;i1<=n;i1++)
	{
		long long xr1=a[i1];
		for(int j1=i1;j1<=n;j1++)
		{
			if(j1!=i1)
				xr1=xr1^a[j1];
			if(xr1==k)
			{
				c[++cnt].l=i1;
				c[cnt].r=j1;
			}
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		int flag=1;
		for(int i1=c[i].l;i1<=c[i].r;i1++)
		{
			if(b[i1]!=0)
			{
				if(b[i1]<c[i].r-c[i].l+1)
				{
					flag=0;
					break;
				}
				else
				{
					flag=2;
				}
			}
		}
		if(flag)
		{
			if(flag==1)
			{
				ans++;
			}
			for(int i1=c[i].l;i1<=c[i].r;i1++)
			{
				b[i1]=c[i].r-c[i].l+1;
			}
		}
	}
	cout<<ans;
}
