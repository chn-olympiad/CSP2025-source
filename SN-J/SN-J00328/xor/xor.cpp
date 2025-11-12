//65
#include<bits/stdc++.h>
using namespace std;
int a[500005],f[500005];
struct node
{
	int l,r;
}b[500005];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,k,t=0,flg=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) flg=0;
	}
	if(flg==1)
	{
		int ans=0;
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1 and a[i-1]==1 and f[i-1]==0)
				{
					ans++;
					f[i]=1;f[i-1]=1;
				}
				if(a[i]==0)
				{
					ans++;
					f[i]=1;
				} 
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long sum=0;
		for(int j=i;j<=n;j++)
		{
			sum=sum^a[j];
			if(sum==k)
			{
				t++;
				b[t].l=i;
				b[t].r=j;
			}
		}
	}
	sort(b+1,b+t+1,cmp);
	int num=0,ans=0;
	for(int i=1;i<=t;i++)
	{
		if(b[i].l>num)
		{
			ans++;
			num=b[i].r;
		}
	}
	cout<<ans;
	return 0;
} 

/*
11 1
1 0 1 1 1 0 1 1 0 1 1
*/
