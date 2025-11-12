#include<bits/stdc++.h>
using namespace std;
int t,n,maxx;
int a[100005][5];
int maxn[100005];

void dfs(int x,int k1,int k2,int k3,int cnt)
{
	if(x==n)
	{
		if(k1<=n/2&&k2<=n/2&&k3<=n/2)maxx=max(cnt,maxx);
		return ;
	}
	dfs(x+1,k1+1,k2,k3,cnt+a[x+1][1]);
	dfs(x+1,k1,k2+1,k3,cnt+a[x+1][2]);
	dfs(x+1,k1,k2,k3+1,cnt+a[x+1][3]);
}

void solve2()//n<=10
{
	dfs(0,0,0,0,0);
	cout<<maxx<<"\n";
	return;
}

void solve1()//n=2
{	
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(i!=j)maxx=max(maxx,a[1][i]+a[2][j]);
		}
	}
	cout<<maxx<<"\n";
	return;
}

void solveA()
{
	for(int i=1;i<=n;i++)
	{
		maxn[i]=max(max(a[i][1],a[i][2]),a[i][3]);
	}
	sort(maxn+1,maxn+n+1);
	for(int i=n;i>n/2;i--)maxx+=maxn[i];
	cout<<maxx<<"\n";
}

void solve0()//C条件及其他 
{
	for(int i=1;i<=n;i++)
	{
		int g=max(max(a[i][1],a[i][2]),a[i][3]);
		maxx+=g;
	}
	cout<<maxx<<"\n";
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		maxx=0;
		scanf("%d",&n);
		bool pA=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(pA==1&&(a[i][2]!=0||a[i][3]!=0))pA=0;
		}
		if(n==2)solve1();
		else if(n<=10)solve2();
		else if(pA==1)solveA();
		else solve0();
	}
	return 0;
}
