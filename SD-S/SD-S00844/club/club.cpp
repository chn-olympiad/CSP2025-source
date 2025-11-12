#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct node
{
	int a,b,c;
}a[100005];
bool cmpa(node a,node b)
{
	return a.a>b.a;
}
bool cmpb(node a,node b)
{
	return a.a-a.b>b.a-b.b;
}
long long ans=0;
int b[100005];
void dfs(int A,int B,int C,long long sum)
{
	if(A+B+C==n)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			if(A<n/2)
			{
				dfs(A+1,B,C,sum+a[i].a);
			}
			if(B<n/2)
			{
				dfs(A,B+1,C,sum+a[i].b);
			}
			if(C<n/2)
			{
				dfs(A,B,C+1,sum+a[i].c);
			}
			b[i]=0;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		bool checkA=true,checkB=true;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b!=0)
			{
				checkA=false;	
			}
			if(a[i].c!=0)
			{
				checkA=false;
				checkB=false;	
			}
		}
		if(checkA)
		{
			sort(a+1,a+n+1,cmpa);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].a;
			}
			printf("%lld\n",ans);
		}
		else if(checkB)
		{
			sort(a+1,a+n+1,cmpb);
			for(int i=1;i<=n;i++)
			{
				if(i<=n/2)
				{
					ans+=a[i].a;
				}
				else
				{
					ans+=a[i].b;	
				}
			}
			printf("%lld\n",ans);
		}
		else
		{
			dfs(0,0,0,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
