#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=2e5+1000,M2=1e3+100;
lint T;
lint n;
struct node{
	lint b1,b2,b3;
	lint hao;
}a[M1],b[M1],d[M1];
bool f[M1];
lint b1,b2,b3;
lint maxn=-1;
void dfs(lint x,lint step,lint c1,lint c2,lint c3)
{
	if(step==n+1)
	{
		if(c1<=n/2&&c2<=n/2&&c3<=n/2) maxn=max(maxn,x);
		return ;
	}
	dfs(x+a[step].b1,step+1,c1+1,c2,c3);
	dfs(x+a[step].b2,step+1,c1,c2+1,c3);
	dfs(x+a[step].b3,step+1,c1,c2,c3+1);
}
bool cmp(node a,node b)
{
	return a.b1>b.b1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		bool fa=1,fb=1;
		scanf("%lld",&n);
		for(lint i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].b1,&a[i].b2,&a[i].b3);
			a[i].hao=i;
			b[i]=a[i];
			d[i]=a[i];
			if(a[i].b3!=0) fb=0;
			if(a[i].b2!=0||a[i].b3!=0) fa=0; 
		}
		if(n<=10)
		{
			dfs(0,1,0,0,0);
			printf("%lld\n",maxn);
			maxn=-1;
		}
		else if(fa)
		{
			sort(a+1,a+n+1,cmp);
			lint sum=0;
			for(lint i=1;i<=n/2;i++) sum+=a[i].b1;
			printf("%lld\n",sum);
		}
	}
	return 0;
}
