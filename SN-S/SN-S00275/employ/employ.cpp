#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=510,P=998244353;

int n,m;
string s;
int c[N];

ll fac[N],inv[N],ans;

ll pw(ll a,ll b)
{
	ll ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%P;
		a=a*a%P; b>>=1;
	} return ret;
}

void init()
{
	fac[0]=inv[0]=1;
	for (int i=1;i<=500;i++) fac[i]=fac[i-1]*i%P;
	inv[500]=pw(fac[500],P-2);
	for (int i=500-1;i;i--) inv[i]=inv[i+1]*(i+1)%P;
}

ll C(int n,int m) {return fac[n]*inv[m]%P*inv[n-m]%P;}

int a[N],v[N];

void dfs(int x)
{
	if (x>n)
	{
		int num=0; 
		for (int i=1;i<=n;i++) if (s[i-1]=='0' || num>=c[a[i]]) num++;
		if (n-num>=m) ans++;
		return;
	}
	
	for (int i=1;i<=n;i++) if (!v[i])
	{
		a[x]=i; v[i]=1; dfs(x+1);
		v[i]=0;
	}
	
}

int num[N];
ll dp[N][N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s; init();
	for (int i=1;i<=n;i++) cin>>c[i];
	if (n<=18)
	{
		dfs(1); cout<<ans; return 0;
	}
	
	for (int i=1;i<=n;i++) num[c[i]]++;
	
	int sum=0;
	for (int i=0;i<=n;i++)
	{
		if (i==0)
		{
			dp[i][0]=fac[num[0]];
			continue;
		}
		
		for (int j=0;j<=n;j++)
		for (int k=0;k<=min(j,num[i]);k++)
		{
			dp[i][j]+=dp[i-1][j-k]%P*pw(min(sum+1,j-k+i),k)%P;
			dp[i][j]%=P;
		}
		sum+=num[i];
	}
	
	for (int i=m;i<=n;i++) ans=(ans+dp[n][i])%P;
	cout<<ans;
	
	return 0;
}


