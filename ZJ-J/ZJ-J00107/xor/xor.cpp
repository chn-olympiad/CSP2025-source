#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,now;
int ss(int i)
{
	int x=0;
	for(int hh=i;hh<=n;hh++)
	{
		x=(x^a[hh]);
		if(x==k) return hh;
	}
	return 0;
}
void solve(int i,int j,int m)
{
	if(i+1>n)
	{
		cout<<ans<<"\n";
		exit(0);
	}
	for(int h=i+1;h<=n;h++)
	{
		j=ss(h);
		if(j)
		{
			i=h;
			break;
		}
	}
	if(!j)
	{
		ans=max(ans,m);
		now++;
		solve(now,0,1);
	}
	m++;
	if(j==n)
	{
		ans=max(ans,m);
		cout<<ans<<"\n";
		exit(0);
	}
	solve(j,0,m);
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i=0,j=0;
	for(int h=1;h<=n;h++)
	{
		j=ss(h);
		if(j)
		{
			i=h;
			break;
		}
	}
	if(!j)
	{
		cout<<"0\n";
		return 0;
	}
	if(j==n)
	{
		cout<<"1\n";
		return 0;
	}
	now=i;
	solve(j,0,1);
	return 0;
}
