#include<iostream>
#include<cstdio>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10;
struct node{
	pair<int,int> a[5];
}a[N];
int n;
int t;
bool cmppii(pair<int,int> x,pair<int,int> y)
{
	return (x.first!=y.first)?(x.first>y.first):(x.second<y.second);
}
bool cmp1(node x,node y)
{
	return (x.a[1].first!=y.a[1].first)?(x.a[1].first>y.a[1].first):(x.a[2].first>y.a[2].first);
}
bool cmp2(node x,node y)
{
	return (x.a[2].first!=y.a[2].first)?(x.a[2].first>y.a[2].first):(x.a[1].first>y.a[1].first);
}
int s[5];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		memset(a,0,sizeof a);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].a[1].first,&a[i].a[2].first,&a[i].a[3].first);
			a[i].a[1].second=1,a[i].a[2].second=2,a[i].a[3].second=3;
			sort(a[i].a+1,a[i].a+4,cmppii);
		}
		sort(a+1,a+n+1,cmp1);
		s[1]=s[2]=s[3]=0;
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			if(s[a[i].a[1].second]<(n>>1))
				s[a[i].a[1].second]++,ans1+=a[i].a[1].first;
			else if(s[a[i].a[2].second]<(n>>1))
				s[a[i].a[2].second]++,ans1+=a[i].a[2].first;
			else
				s[a[i].a[3].second]++,ans1+=a[i].a[3].first;
		}
		sort(a+1,a+n+1,cmp2);
		s[1]=s[2]=s[3]=0;
		int ans2=0;
		for(int i=1;i<=n;i++)
		{
			if(s[a[i].a[2].second]<(n>>1))
				s[a[i].a[2].second]++,ans2+=a[i].a[2].first;
			else if(s[a[i].a[1].second]<(n>>1))
				s[a[i].a[1].second]++,ans2+=a[i].a[1].first;
			else
				s[a[i].a[3].second]++,ans2+=a[i].a[3].first;
		}
		printf("%lld\n",max(ans1,ans2));
	}
	return 0;
}
/*
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
freopen(".in","w",stdin);
freopen(".out","r",stdout);
feropen(".in","r",stdin);
feropen(".out","w",stdout);
I'm luogu uid748678.
Maybe it's my last year in CSP/NOIP.
Hope everything goes best.
*/
