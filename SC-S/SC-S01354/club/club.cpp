#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
struct node
{
	int a,b,c;
}a[200005];
void dfs(int k,int c1,int c2,int c3,int sum)
{
	int mx=max({c1,c2,c3});
	if(mx>n/2)return;
	if(k==n)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(k+1,c1+1,c2,c3,sum+a[k+1].a);
	dfs(k+1,c1,c2+1,c3,sum+a[k+1].b);
	dfs(k+1,c1,c2,c3+1,sum+a[k+1].c);
}
bool cmp(node s1,node s2)
{
	return s1.a>s2.a;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
		if(n<=15)
		{
			dfs(0,0,0,0,0);
			cout<<ans<<"\n";
		}
		else
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i].a;
			cout<<ans<<"\n";
		}
	}
}