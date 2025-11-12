#include<bits/stdc++.h>
using namespace std;
int n,sumd;
int a[10001],b[10001],t[10001],ta[10001];
void dfs(int c)
{
	if(c==n)
	{
		if(t[c]>2*ta[c])
		{
			sumd++;
		}
		return;
	}
	for(int i=c+1;i<=n;i++)
	{
		t[c]+=a[i];
		ta[c]=max(ta[c],a[i]);
		dfs(i+1);
		t[c]-=a[i];
		dfs(i);
	}
}
int main()
{
	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	int x=0,g=0;
	long long sum=0,xx=0;
	cin>>n;
	if(n<=3)
	{
		int y=0,yy=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			y=max(y,a[i]);
			yy+=a[i];
		}
		if(yy>y*2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=max(x,a[i]);
	}
	if(x==1)
	{
		int cnt=0;
		for(int i=1;i<=n-2;i++)
		{
			cnt+=i;
			b[i]=b[i-1]+cnt;
		}
		for(int i=1;i<=n-2;i++)
		{
			b[i]=b[i]%998;
		}
		for(int i=1;i<=n-2;i++)
		{
			sum+=b[i];
		}
	}
	else
	{
		dfs(1);
		cout<<sumd;
		return 0;
	}
	cout<<sum%998%244%353;
	return 0;
} 
