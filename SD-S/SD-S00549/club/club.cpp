#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int n;
struct node{
	int x;
	int y;
	int z;
}a[100010],ca[100010];
bool cmp1(node a,node b)
{
	if(a.x==b.x)
	{
		if(a.y==b.y)
		{
			return a.z>b.z;
		}
		return a.y>b.y;
	}
	return a.x>b.x;
}
int ans=0;
void dfs(int x,int nans,int c1,int c2,int c3)
{
	if(x==n+1)
	{
		ans=max(nans,ans);
	}
	else
	{
		dfs(x+1,nans+a[i].x,c1+1,c2,c3);
		dfs(x+1,nans+a[i].y,c1,c2+1,c3);
		dfs(x+1,nans+a[i].z,c1,c2,c3+1);
	}
}
signed main()
{
	//freopen("club.in","r",stdin); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		ca[i].x=a[i].x;
		ca[i].y=a[i].y;
		ca[i].z=a[i].z;
	}
	ans=0;
	if(n<=30)
	{
		dfs(1,0,0,0,0);
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			ans+=a[i].x+a[i].y;
		}
	}
	cout<<ans<<"\n";
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
