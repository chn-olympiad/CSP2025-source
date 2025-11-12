#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],maxn,sum,cnt,maxl;
void f(int j,int x)
{
	if(x==j+1)
	{
		cnt++;
		return;
	}
	for(int i=b[x-1]+1;i<=j;i++)
	{
		b[x]=i;
		f(j,x+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		for(int i=1;i<=3;i++)
		{
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
		if(sum>(2*maxn))
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			f(i,1);
			cnt%=998244353;
		}
		cout<<cnt;
	}
	return 0;
}
