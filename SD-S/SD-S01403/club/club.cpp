#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=100005;
struct node
{
	int a,b,c;
};
bool cmp_a(node x,node y)
{
	return x.a>y.a;
}
node a[MAXN];
int n,maxnum;
int f[205][205][205];  //choose i ppl,j ppl is in 1,k ppl is in 2 
bool check_A()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].b==0&&a[i].c==0)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
void solve_A()
{
	sort(a+1,a+1+n,cmp_a);
	int ans=0,cnt=0;
	for(int i=1;i<=(n/2);i++)
	{
		ans+=a[i].a;
	}
	printf("%d\n",ans);
}
void solve_C()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=max(a[i].a,max(a[i].b,a[i].c));
	}
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxnum=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		if(check_A())
		{
			solve_A();
			continue;
		}
		if(n>200)
		{
			solve_C();
			continue;
		}
		memset(f,0,sizeof(f));
		f[1][1][0]=a[1].a;
		f[1][0][1]=a[1].b;
		f[1][0][0]=a[1].c;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=maxnum;j++)
			{
				for(int k=0;k<=maxnum;k++)
				{
					int cc=i-j-k;
					if(cc<0||cc>=maxnum)
					{
						continue;
					}
					if(j!=0)
					{
						f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i].a);
					}
					if(k!=0)
					{
						f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].b);
					}
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].c);
				}
			}
		}
		int ans=0;
		for(int j=0;j<=maxnum;j++)
		{
			for(int k=0;k<=maxnum;k++)
			{
				int cc=n-j-k;
				if(cc>maxnum||cc<0)
				{
					continue;
				}
				ans=max(ans,f[n][j][k]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

