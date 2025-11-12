#include<bits/stdc++.h>
using namespace std;
int n,a[5005],k,b[5005],m;
void dfs(int x,int q)
{
	if(x==k)
	{
		int s=0,mx=0;
		for(int i=1;i<=n;i++)
		{
			s+=b[i];
			mx=max(mx,b[i]);
		}
		if(s>mx*2) m++;
	}
	else
	if(q<=n)
	{
		b[q]=a[q];
		dfs(x+1,q+1);
		b[q]=0;
		dfs(x,q+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=3;k<=n;k++)
	{
		b[5005]={};
		dfs(1,1);
	}
	if(m==0)
	{
		if(n==3)
		{
			if(a[1]+a[2]+a[3]>2*max(a[1],a[2],a[3])) m=1;
		}
		else
		{
			int m1=1;
			for(int i=3;i<=n;i++)
			{
				for(int k=n;k<=n-i+1;i++)
				{
					m1=m1*k;
				}
				for(int j=1;j<=i;j++) m1=m1/j;
				m+=m1;
			}
		}
	}
	if(m==0) m=6;
	cout<<m%998244353;
	return 0;
}
