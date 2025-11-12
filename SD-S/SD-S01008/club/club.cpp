#include <bits/stdc++.h>
using namespace std;
int T;
int n;
long long ans;
long long dis1;
struct node
{
	int dis,ma,i1,i2;
}p[100005];
int cnt[4];
bool cmp(node a,node b)
{
	return a.dis>b.dis;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		dis1=0;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b)
			{
				if(b>=c)
				{
					p[i]=node{a-b,a,1,2};
				}
				else
				{
					if(a>=c)
					{
						p[i]=node{a-c,a,1,3};
					}
					else
					{
						p[i]=node{c-a,c,3,1};
					}
				}
			}
			else
			{
				if(a>=c)
				{
					p[i]=node{b-a,b,2,1};
				}
				else
				{
					if(b>=c)
					{
						p[i]=node{b-c,b,2,3};
					}
					else
					{
						p[i]=node{c-b,c,3,2};
					}
				}
			}
			ans+=p[i].ma;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt[p[i].i1]<(n/2))
			{
				cnt[p[i].i1]++;
			}
			else
			{
				cnt[p[i].i2]++;
				dis1+=p[i].dis;
			}
		}
		cout<<ans-dis1<<endl;
	}
	return 0;
}
