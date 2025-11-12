//SN-S00739 陈和骏 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
char c[N];
int a[N],ans,n,m,vis[N],jc[N];
void dfs(int u,int cnt,int now)
{
//	cout<<u<<" "<<cnt<<" "<<now<<"\n";
	if(u==n+1)
	{
		if(now>=m) ans++;
		return;
	}
	if(now==m)
	{
		ans=(ans+jc[n-u+1])%mod;
		return; 
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(c[u]=='0') dfs(u+1,cnt+1,now);
		else dfs(u+1,cnt+(cnt>=a[i]),now+(cnt<a[i]));
		vis[i]=0;
	}
}
int rd()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
	}
	else if(x<10)
	{
		putchar(x+'0');
		return;
	}
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	cin>>c+1;
	for(int i=1;i<=n;i++) cin>>a[i];
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	dfs(1,0,0);
	write(ans);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
