#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,MOD=998244353;
int n,m,A[N],C[N],vis[N],ans,fc[N],aa[N];
char c[N];
void DFS(int k,int a)
{
	if(a+(n-k+1)<m) return ;
	if(a>=m)
	{
		ans=(ans+fc[n-k+1])%MOD;
		return ;
	}
	if(k==n+1) return ;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;aa[k]=i;
			DFS(k+1,c[k]=='0'?a:(k-a-1>=C[i]?a:a+1));
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%lld%lld%s",&n,&m,c+1);
	fc[0]=1;
	for(int i=1;i<=n;i++)
		scanf("%lld",&C[i]),
		fc[i]=(fc[i-1]*i)%MOD;
	DFS(1,0);
	printf("%d\n",ans);
	return 0;
}
