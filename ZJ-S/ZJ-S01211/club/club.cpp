#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct Node
{
	int v1,v2,v3;
}a[N];

int ans,n;

inline void dfs(int step,int sum1,int sum2,int sum3,int sum)
{
	if(sum1>n/2 || sum2>n/2 || sum3>n/2) return;
	if(step>n)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(step+1,sum1+1,sum2,sum3,sum+a[step].v1);
	dfs(step+1,sum1,sum2+1,sum3,sum+a[step].v2);
	dfs(step+1,sum1,sum2,sum3+1,sum+a[step].v3);
}

bool cmp1(Node x,Node y) 
{
	return x.v1>y.v1;
}

inline void calc()
{
	ans=0;
	scanf("%d",&n);
	bool flag1=true,flag2=true;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d%d",&a[i].v1,&a[i].v2,&a[i].v3);
		if(a[i].v2!=0) flag1=false;
		if(a[i].v3!=0) flag1=flag2=false;
	}
	if(flag1)
	{
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++) ans+=a[i].v1;
	}
	else dfs(1,0,0,0,0);
	printf("%d\n",ans);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) calc();
	return 0;
}
