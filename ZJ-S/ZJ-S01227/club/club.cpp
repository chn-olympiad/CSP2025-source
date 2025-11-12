#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
int n;
int T;
int ans;
int cnt[4];
int sol[50][3];
int C[4];
struct stu
{
	int one,two,three;
	int delta_one;
	int opt;
}a[N];
bool cmp1(stu x,stu y)
{
	return x.delta_one > y.delta_one ;
}
void dfs(int x,int value)
{
	if( x == n+1 )
	{
		ans = max( ans,value );
		return ;
	}
	for(int i=0;i<3;i++)
	{
		if( C[i] == n/2 ) continue;
		C[i]++;
		dfs(x+1,value+sol[x][i]);
		C[i]--;
	}
}
void solve1()
{ 
	for(int i=1;i<=n;i++)
	{
		sol[i][0]=a[i].one;
		sol[i][1]=a[i].two;
		sol[i][2]=a[i].three;
	}
	dfs(1,0);
}
int main()
{
	freopen("club.in","in",stdin);
	freopen("club.out","out",stdout); 
	scanf("%d",&T);
	while(T--)
	{
		ans = 0 ;
		cnt[1]=cnt[2]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].one,&a[i].two,&a[i].three);
			a[i].delta_one = abs( a[i].one - a[i].two ) ;
		}
		if(n<=30)
		{
			memset(sol,0,sizeof sol);
			memset(C,0,sizeof C);
			solve1();
			printf("%d\n",ans);
			continue;
		}
		sort(a+1,a+1+n,cmp1);
		int x = 0;
		for(int i=1;i<=n;i++)
		{
			if( a[i].one > a[i].two )
			{
				if( cnt[1]==n/2 ) 
				{
					x = i;
					break;
				}
				a[i].opt = 1;
				cnt[1]++;
			}
			else
			{
				if( cnt[2]==n/2 )
				{
					x = i;
					break;
				}
				a[i].opt = 2 ;
				cnt[2]++;
			}
		}
		for(int i=x;i<=n;i++)
		{
			if( cnt[1]==n/2 ) a[i].opt=2;
			else a[i].opt=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].opt==1) ans+=a[i].one;
			else ans+=a[i].two;
		}
		printf("%d\n",ans);
	}
}