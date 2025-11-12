#include<bits/stdc++.h>
using namespace std;
int T;
struct stuent{
	int a,b,c;
	int f1;
	int mx;
	int num;
	
}s[100005];
bool cmp(stuent a,stuent b)
{
	return a.mx>=b.mx;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int ans=0;
		int cnta=1,cntb=1,cntc=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			//s[i].num=i;
			if(s[i].a>=s[i].b && s[i].a>=s[i].c)
			{
				s[i].f1=1;
			}
			else{
				if(s[i].b>=s[i].a && s[i].b>=s[i].c)
				{
					s[i].f1=2;
				}
				else
				{
					s[i].f1=3;
				}
			}
			int q;
			if(s[i].f1==1)
			{
				q=max(s[i].b,s[i].c);
				s[i].mx=s[i].a-q;
			}
			if(s[i].f1==2)
			{
				q=max(s[i].a,s[i].c);
				s[i].mx=s[i].b-q;
			}
			if(s[i].f1==3)
			{
				q=max(s[i].a,s[i].b);
				s[i].mx=s[i].c-q;
			}
		}
		
		int maxx=n/2;
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(s[i].f1==1)
			{
				if(cnta<=maxx)
				{
					ans+=s[i].a;
					cnta++;
				}
				else{
					ans+=max(s[i].b,s[i].c);
				}
			}
			if(s[i].f1==2)
			{
				if(cntb<=maxx)
				{
					ans+=s[i].b;
					cntb++;
				}
				else{
					ans+=max(s[i].a,s[i].c);
				}
			}
			if(s[i].f1==3)
			{
				if(cntc<=maxx)
				{
					ans+=s[i].c;
					cntc++;
				}
				else{
					ans+=max(s[i].a,s[i].b);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
