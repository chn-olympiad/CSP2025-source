#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
int re();
void wr(ll x);
int T,n;
struct node
{
	int a,b,c,ma,mb,mtot;
	bool operator < (const node &tem)const
	{
		return ma+tem.mb < mb+tem.ma;
	}
}q[100010];
priority_queue <node> que;
int ta,tb,tc;
ll ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=re();
	while(T--)
	{
		n=re();
		ans=ta=tb=tc=0;
		for(int i=1;i<=n;i++)
		{
			q[i].a=re();
			q[i].b=re();
			q[i].c=re();
			while(!que.empty()) que.pop();
			if(q[i].a>=q[i].b && q[i].a>=q[i].c)
			{
				ta++;
				q[i].ma=q[i].a;
				q[i].mb=max(q[i].b,q[i].c);
				q[i].mtot=1;
			}
			if(q[i].b>=q[i].a && q[i].b>=q[i].c)
			{
				tb++;
				q[i].ma=q[i].b;
				q[i].mb=max(q[i].a,q[i].c);
				q[i].mtot=2;
			}
			if(q[i].c>=q[i].b && q[i].c>=q[i].a)
			{
				tc++;
				q[i].ma=q[i].c;
				q[i].mb=max(q[i].b,q[i].a);
				q[i].mtot=3;
			}
		}
		if(ta>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(q[i].mtot==1)
				{
					que.push(q[i]);
				}
			}
			int temn=que.size();
			for(int i=1;i<=temn;i++)
			{
				node tem=que.top();
				que.pop();
				if(i<=n/2)
				{
					ans+=tem.ma;
				}
				else
				{
					ans+=tem.mb;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(q[i].mtot!=1) ans+=q[i].ma;
			}
		}
		else if(tb>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(q[i].mtot==2)
				{
					que.push(q[i]);
				}
			}
			int temn=que.size();
			for(int i=1;i<=temn;i++)
			{
				node tem=que.top();
				que.pop();
				if(i<=n/2)
				{
					ans+=tem.ma;
				}
				else
				{
					ans+=tem.mb;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(q[i].mtot!=2) ans+=q[i].ma;
			}
		}
		else if(tc>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(q[i].mtot==3)
				{
					que.push(q[i]);
				}
			}
			int temn=que.size();
			for(int i=1;i<=temn;i++)
			{
				node tem=que.top();
				que.pop();
				if(i<=n/2)
				{
					ans+=tem.ma;
				}
				else
				{
					ans+=tem.mb;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(q[i].mtot!=3) ans+=q[i].ma;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans+=q[i].ma;
			}
		}
		wr(ans);
		putchar('\n');
	}
	return 0;
}
int re()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void wr(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		wr(x/10);
	}
	putchar(x%10+'0');
}

