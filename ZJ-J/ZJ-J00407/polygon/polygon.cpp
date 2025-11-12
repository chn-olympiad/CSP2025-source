#include<bits/stdc++.h>
using namespace std;
int summ;int n;int cnt;int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
void f(int x,int off_sum,int maxx,int c)
{
	if(n-c==2 || x>n)
	{
		return;
	}
	int sum=summ-off_sum;
	if(sum>maxx*2)
	{
		cnt+=(cnt+1)%998244353;
	}
	if(a[x+1]==maxx)
	{
		f(x+1,off_sum+a[x+1],a[x+2],c+1);
		for(int i=x+2;i<=n;i++)
		{
			f(i,off_sum+a[i],maxx,c+1);
		}
	}
	else
	{
		for(int i=x+1;i<=n;i++)
		{
			f(i,off_sum+a[i],maxx,c+1);
		}
	}
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		summ+=a[i];
	}
	f(1,a[1],a[2],1);
	for(int i=2;i<=n;i++)
	{
		f(i,a[i],a[1],1);
	}
	cout<<cnt+1;
	ios::sync_with_stdio(0);
	return 0;
}
