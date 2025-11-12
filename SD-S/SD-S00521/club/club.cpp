#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
const int N=1e5+10,M=201;
int t,n,ans,dp[N][2],t1=0,t2;
struct Node{
	int x,y,z;
}a[N];
inline void dfs(int k,int x,int y,int z,int p)
{
	if(k>n){ans=max(ans,p);return;}
	if(x<n/2)dfs(k+1,x+1,y,z,p+a[k].x);
	if(y<n/2)dfs(k+1,x,y+1,z,p+a[k].y);
	if(z<n/2)dfs(k+1,x,y,z+1,p+a[k].z);
	return;
}
inline bool cmp(Node a,Node b)
{
	return a.x>b.x;
}
inline bool pd()
{
	for(int i=1;i<=n;i++)if(a[i].y||a[i].z)return 0;
	return 1;
}
inline bool pd1()
{
	for(int i=1;i<=n;i++)if(a[i].z)return 0;
	return 1;
}
inline bool c1(Node x,Node y)
{
	return x.x>y.x||(x.x==y.x&&x.y>y.y);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}
		else
		{
			if(pd())
			{
				stable_sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++)ans+=a[i].x;
				cout<<ans<<'\n';
			}
			else
			{t1=0;t2=0;int maxn=0;
				stable_sort(a+1,a+n+1,c1);
				for(int i=1;i<=n;i++)
				{
					maxn=max(a[i].x,a[i].y);
	if((maxn==a[i].x&&t1<n/2)||t2==n/2){ans+=a[i].x;t1++;}
					else{t2++;ans+=a[i].y;}
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}
