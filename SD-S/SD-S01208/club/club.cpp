#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N],a1,b1,c1,maxx,n;
void dfs(int i,int s)
{
	if(i==n+1)
	{
		maxx=max(maxx,s);
		return ;
	}
	if(a1<n/2)
	{
		a1++;
		dfs(i+1,s+a[i]);
		a1--;
	}
	if(b1<n/2)
	{
		b1++;
		dfs(i+1,s+b[i]);
		b1--;
	}
	if(c1<n/2)
	{
		c1++;
		dfs(i+1,s+c[i]);
		c1--;
	}
}
int main()
{
	int t,i,ans=0,sum=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;sum=0;maxx=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(!a[i]) sum++;
			if(!b[i]) sum++;
			if(!c[i]) sum++;
		}
		if(n<=10)
		{
			dfs(1,0);
			ans=maxx;
			cout<<ans<<endl;
			continue;
		}
		if(sum==2*n)
		{
			sort(a+1,a+n+1);
			for(i=n;i>n/2;i--)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
