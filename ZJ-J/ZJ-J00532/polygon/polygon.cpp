#include<bits/stdc++.h>
using namespace std;
const int N=5e3+7;
const int MOD=998244353;
int n,A[N],pre[N];
long long f[N],ans;
int dfs(int x,int y,int mx,int sum)
{
	if(x>n)
		return y>=3&&mx*2<sum;
	if(mx*2>=sum+pre[x])
		return 0;
	return ( dfs(x+1,y+1,max(mx,A[x]),sum+A[x]) + dfs(x+1,y,mx,sum) )%MOD;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n<=30)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>A[i];
		}
		for(int i=n;i>=1;i--)
		{
			pre[i]=pre[i+1]+A[i];
		}
		cout << dfs(1,0,0,0)%MOD<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>A[i];
		}
		f[0]=1,f[n]=1;
		for(int i=1;i*2<=n;i++)
		{
			f[i]=f[i-1]*(n-i+1)/i%MOD;
			f[n-i]=f[i];
		}
		for(int i=3;i<=n;i++)
			ans=(ans+f[i])%MOD;
		cout <<ans<<endl;
	}
	return 0;
}
