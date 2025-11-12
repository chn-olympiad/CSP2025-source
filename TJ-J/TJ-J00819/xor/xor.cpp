#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],top=1,p=0,d[500005];
bool sum[1050005];
long long ans;
int ehuo(int x,int y)
{
	int p=x|y;
	int q=x&y;
	return p-q;
}
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n<=500)
	{
		for (int l=1;l<=n;l++)
		{
			for (int r=l;r<=n;r++)
			{
				int p=a[l];
				for (int i=l+1;i<=r;i++)
				{
					p=ehuo(p,a[i]);
				}
				if (p==k)
				{
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	bool v=true;
	for (int i=1;i<=n;i++)
	{
		if (v)
		{
			v=false;
			sum[0]==0;
			p=a[i];
		}
		else
		{
			p=ehuo(p,a[i]);
		}
		d[i]=p;
		if (sum[ehuo(p,k)])
		{
			for (int j=top;j<=i;j++)
			{
				sum[d[j]]=false;
			}
			top=i+1;
			p=0;
			v=true;
			ans++;
		}
		sum[p]=true;
	}
	cout<<ans;
}
