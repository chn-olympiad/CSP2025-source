#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
long long T,n,a[N],b[N],c[N];
long long ans,res;

inline void dfs(long long t,long long sum1,long long sum2,long long sum3)
{
	if(t==n+1)
	{
		ans=max(ans,res);
//		cout<<res<<"\n";
		return;
	}
	long long k1=res;
	if(sum1<n/2)
	{
		res+=a[t];
		dfs(t+1,sum1+1,sum2,sum3);
		res=k1;
	}
	
	if(sum2<n/2&&b[t]!=a[t])
	{
		res+=b[t];
		dfs(t+1,sum1,sum2+1,sum3);
		res=k1;
	}
	
	if(sum3<n/2&&b[t]!=c[t]&&c[t]!=a[t])
	{
		res+=c[t];
		dfs(t+1,sum1,sum2,sum3+1);
		res=k1;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		ans=res=0;
		for(long long i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		dfs(1,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
