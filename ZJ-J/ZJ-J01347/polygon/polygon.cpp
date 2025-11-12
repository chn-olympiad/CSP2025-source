#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005];
//int qzh[5005];
int ans,sum,maxn;
int cnt;
int mark[5005];
int b[5005];
int c[5005][5005];
int len;
void dfs(int x)
{
//	if(mark[x])
//	{
//		ans+=mark[x];
//		return;
//	} 
	if(x>n)
	{
		if(sum>(2*maxn) && cnt>=3)
		{
			ans++;
//			for(int i=1;i<=len;i++)
//				printf("%lld ",b[i]);
//			printf("maxn=%lld\n",maxn);
//			printf("\n");
		}
		ans%=998244353;
		return;
	}
	int maxnn=maxn;
	dfs(x+1);
	sum+=a[x];
	maxn=max(maxn,a[x]);
	cnt++;
	b[++len]=x;
	dfs(x+1);
	b[len]=0;
	len--;
	cnt--;
	maxn=maxnn;
	sum-=a[x];
	mark[x]=ans;
}
int pf_1_1,pf_1_2;
int sum2;
int pf_1_2_f()
{
	for(int i=1;i<=n;i++)
		c[i][1]=i;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%98244353;
		}
	for(int i=3;i<=n;i++)
		sum2+=(c[n][i]%998244353);
	return sum2%998244353;
}
signed main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		pf_1_2=max(pf_1_2,a[i]);
		pf_1_1+=a[i];
	}
	if(pf_1_1<2*pf_1_2) 
	{
		printf("0");
		return 0;
	}
	if(pf_1_2==1)
	{
		printf("%lld",pf_1_2_f());
		return 0;
	} 
	//sort(a+1,a+n+1);
	dfs(1);
//	for(int i=1;i<=n;i++)
//		qzh[i]+=a[i];
//	for(int i=n;i>=1;i--)
//	{
//		for(int j=1;j<=n-1;j++)
//		{
//			if(a[j+1]+a[j]>a[i])
//		}
//	}
	printf("%lld",ans);
	return 0;//400稳了！
}