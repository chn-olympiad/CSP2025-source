#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

const int N=5010,P=998244353;

int n,a[N];
ll dp[2][N][3],ans;

ll pw(ll a,ll b)
{
	ll ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%P;
		a=a*a%P; b>>=1;
	} 
	return ret;
}

ll fac[N],inv[N];
ll C(int n,int m) {if (m>n) return 0; return fac[n]*inv[m]%P*inv[n-m]%P;}

void init()
{
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%P;
	inv[n]=pw(fac[n],P-2);
	for (int i=n-1;i;i--) inv[i]=inv[i+1]*(i+1)%P;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n; init(); 
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	int now=1,pre=0; dp[pre][0][0]=1;
	for (int i=1;i<=n;i++)
	{
		ll sum=0;
		for (int j=2;j<i;j++) sum=(sum+C(i-1,j))%P;
		for (int j=0;j<=a[i];j++) sum=(sum-dp[pre][j][2]+P)%P;
		ans+=sum; ans%=P; 
		
		for (int j=0;j<=a[n];j++)
		for (int k=0;k<=2;k++)
		{
			dp[now][j][k]=dp[pre][j][k];
			if (j>=a[i] && k) dp[now][j][k]+=dp[pre][j-a[i]][k-1];
			if (k==2 && j>=a[i]) dp[now][j][k]+=dp[pre][j-a[i]][2];
			dp[now][j][k]%=P;
		}
		
		swap(now,pre);
	}
	
	cout<<ans;

 	return 0;
}





