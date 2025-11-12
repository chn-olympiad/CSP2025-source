#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=514;
const int MOD=998244353;
int n,m,s[M],c[M];
char t[M];
int f[1<<18][20];
int sum[M];
int Get(int n)
{
	int cnt=0;
	while(n) cnt++,n&=(n-1);
	return cnt;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",t);
	int v=0,ss=0;
	for(int i=0;i<n;i++)
		s[i]=t[i]-'0',ss+=(s[i]==0),sum[i]=ss;
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	f[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++)
	{
		int m=Get(i);
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(((i>>k)&1)) continue;
				int ii=i^(1<<k),jj=j;
				if(s[m]!=0&&m-j<c[k]) jj++;
				if(jj>=0) f[ii][jj]=(f[ii][jj]+f[i][j])%MOD;
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) ans=(ans+f[(1<<n)-1][i])%MOD;
	cout<<ans;
	return 0;
}

