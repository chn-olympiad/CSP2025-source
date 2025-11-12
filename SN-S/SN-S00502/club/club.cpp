#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node
{
	int a,b,c;
}p[100010],q[100010];
node yi[100010],er[100010],san[100010];
int c1,c2,c3;
bool cmp(node g,node h)
{
	return g.c<h.c;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a>>p[i].b>>p[i].c;
		if(p[i].a>=p[i].b&&p[i].a>=p[i].c)
		{
			if(p[i].b>=p[i].c)yi[++c1]={i,p[i].a,p[i].a-p[i].b};
			else yi[++c1]={i,p[i].a,p[i].a-p[i].c};
		}
		else if(p[i].b>=p[i].a&&p[i].b>=p[i].c)
		{
			c2++;
			if(p[i].a>=p[i].c)er[c2]={i,p[i].b,p[i].b-p[i].a};
			else er[c2]={i,p[i].b,p[i].b-p[i].c};
		}
		else
		{
			if(p[i].a>=p[i].b)san[++c3]={i,p[i].c,p[i].c-p[i].a};
			else san[++c3]={i,p[i].c,p[i].c-p[i].b};
		}
	}
	int ans=0;
	if(c1>n/2)
	{
		sort(yi+1,yi+c1+1,cmp);
		for(int i=1;i<=c1;i++)
		{
			ans+=yi[i].b;
		}
		for(int i=1;i<=c1-n/2;i++)
		{
			ans-=yi[i].c;
		}
		for(int i=1;i<=c2;i++)
		{
			ans+=er[i].b;
		}
		for(int i=1;i<=c3;i++)
		{
			ans+=san[i].b;
		}
	}
	else if(c2>n/2)
	{
		sort(er+1,er+c2+1,cmp);
		for(int i=1;i<=c2;i++)
		{
			ans+=er[i].b;
		}
		for(int i=1;i<=c2-n/2;i++)
		{
			ans-=er[i].c;
		}
		for(int i=1;i<=c3;i++)
		{
			ans+=yi[i].b;
		}
		for(int i=1;i<=c3;i++)
		{
			ans+=san[i].b;
		}
	}
	else if(c3>n/2)
	{
		sort(san+1,san+c3+1,cmp);
		for(int i=1;i<=c3;i++)
		{
			ans+=san[i].b;
		}
		for(int i=1;i<=c3-n/2;i++)
		{
			ans-=san[i].c;
		}
		for(int i=1;i<=c2;i++)
		{
			ans+=er[i].b;
		}
		for(int i=1;i<=c1;i++)
		{
			ans+=yi[i].b;
		}
	}
	else
	{
		for(int i=1;i<=c1;i++)
		{
			ans+=yi[i].b;
		}
		for(int i=1;i<=c2;i++)
		{
			ans+=er[i].b;
		}
		for(int i=1;i<=c3;i++)
		{
			ans+=san[i].b;
		}
	}
	cout<<ans<<endl;
	c1=c2=c3=0;
	
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
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
*/
