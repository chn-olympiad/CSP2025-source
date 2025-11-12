#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c,id,ma,cma,cha;
}a[100005];
bool vis[100005];
int t,n,s=0,ma=0,ta=0,tb=0,tc=0;
bool cmp(node x,node y)
{
	return x.cha>y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].id=i;
			a[i].ma=max({a[i].a,a[i].b,a[i].c});
			if(a[i].ma==a[i].a) a[i].cma=max(a[i].b,a[i].c);
			if(a[i].ma==a[i].b) a[i].cma=max(a[i].a,a[i].c);
			if(a[i].ma==a[i].c) a[i].cma=max(a[i].a,a[i].b);
			a[i].cha=a[i].ma-a[i].cma;
		}
		sort(a+1,a+n+1,cmp);
		s=ta=tb=tc=0;
		for(int i=1;i<=n;i++)
		{
			if(ta<n/2&&a[i].ma==a[i].a)
			{
				s+=a[i].a,ta++;
				continue;
			}
			if(tb<n/2&&a[i].ma==a[i].b)
			{
				s+=a[i].b,tb++;
				continue;
			}
			if(tc<n/2&&a[i].ma==a[i].c)
			{
				s+=a[i].c,tc++;
				continue;
			}
			if(ta<n/2&&a[i].cma==a[i].a)
			{
				s+=a[i].a,ta++;
				continue;
			}
			if(tb<n/2&&a[i].cma==a[i].b)
			{
				s+=a[i].b,tb++;
				continue;
			}
			if(tc<n/2&&a[i].cma==a[i].c)
			{
				s+=a[i].c,tc++;
				continue;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
