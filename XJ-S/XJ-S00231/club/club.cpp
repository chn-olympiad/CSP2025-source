#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct node
{
	int s1,s2,s3;
}a[N];
int t,n;
bool cmp(node x,node y)
{
	return x.s1>y.s1;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
		}
		int ans=0;
		if(n==2)
		{
			ans=max({a[1].s1+a[2].s2,a[1].s1+a[2].s3,a[1].s2+a[2].s1,a[1].s2+a[2].s3,a[1].s3+a[2].s1,a[1].s3+a[2].s2});
			cout<<ans<<'\n';
		}
		else
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].s1;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
