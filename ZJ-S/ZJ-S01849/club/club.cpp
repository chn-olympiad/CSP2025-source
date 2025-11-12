#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N][4],ch[N][4],pos[N];
struct player
{
	int first,second;
	bool operator<(const player &e)const
	{
		return a[second][ch[second][1]]-a[second][ch[second][2]]>a[e.second][ch[e.second][1]]-a[e.second][ch[e.second][2]];
	}
};
priority_queue<player> q[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])
			{
				ch[i][1]=1;
				ch[i][2]=2;
				ch[i][3]=3;
			}
			if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
			{
				ch[i][1]=2;
				ch[i][2]=1;
				ch[i][3]=3;
			}
			if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])
			{
				ch[i][1]=1;
				ch[i][2]=3;
				ch[i][3]=2;
			}
			if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])
			{
				ch[i][1]=2;
				ch[i][2]=3;
				ch[i][3]=1;
			}
			if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1])
			{
				ch[i][1]=3;
				ch[i][2]=2;
				ch[i][3]=1;
			}
			if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])
			{
				ch[i][1]=3;
				ch[i][2]=1;
				ch[i][3]=2;
			}
		}
		int lim=n/2;
		for(int i=1;i<=n;i++)  //here, we should insert someone new
		{
			int st1=ch[i][1],st2=ch[i][2],name;
			if(q[st1].size())
				name=q[st1].top().second;	
			if(q[st1].size()<lim) //situation 1. A
			{
				q[st1].push({a[i][st1],i});
				continue;
			}
			if(q[st1].top().first+a[i][st2]<a[name][ch[name][2]]+a[i][st1])// situation 1.B
			{
				q[st1].pop();
				q[st1].push({a[i][st1],i});
				q[ch[name][2]].push({a[name][ch[name][2]],name});
			}
			else
			{
				q[st2].push({a[i][st2],i});
			}
		}
		int ans=0;
		while(!q[1].empty())
		{
			ans+=q[1].top().first;
			q[1].pop();
		}
		while(!q[2].empty())
		{
			ans+=q[2].top().first;
			q[2].pop();
		}
		while(!q[3].empty())
		{
			ans+=q[3].top().first;
			q[3].pop();
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
*/