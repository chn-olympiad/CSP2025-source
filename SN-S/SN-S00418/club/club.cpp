//林靖轩 SN-S00418 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T; 
struct node{
	int a,b,c;
}e[N];
bool cmpa(node x,node y)
{
	return x.a>y.a;
}
bool cmpb(node x,node y)
{
	return x.b>y.b;
}
bool cmpc(node x,node y)
{
	return x.c>y.c;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n,ans=0,aa=0,bb=0,cc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>e[i].a>>e[i].b>>e[i].c;
		int cnt=n/2;
		sort(e+1,e+n+1,cmpc);
		sort(e+1,e+n+1,cmpb);
		sort(e+1,e+n+1,cmpa);
		for(int i=1;i<=n;i++)
		{
			if(aa==cnt)
			{
				ans+=max(e[i].b,e[i].c);
				continue;
			}
			if(bb==cnt)
			{
				ans+=max(e[i].a,e[i].c);
				continue;
			}
			if(cc==cnt)
			{
				ans+=max(e[i].b,e[i].a);
				continue;
			}
			
			if(e[i].a>e[i].b && e[i].a>e[i].c && aa<cnt)aa++,ans+=e[i].a;
			else if(e[i].b>e[i].a && e[i].b>e[i].c && bb<cnt)bb++,ans+=e[i].b;
			else if(e[i].c>e[i].b && e[i].c>e[i].a && cc<cnt)cc++,ans+=e[i].c;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
// 3
// 4
// 4 2 1
// 3 2 4
// 5 3 4
// 3 5 1
// 4
// 0 1 0
// 0 1 0
// 0 2 0
// 0 2 0
// 2
// 10 9 8
// 4 0 0

