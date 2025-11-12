#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,m,k,t,a[N],s[N],cf[N];
int q[N],dp[N];
int ccc=0;
char b[N];
int A(int x,int y)
{
	int sum=1;
	for(int i=1;i<=y;i++)
	{
		sum*=(x-i+1);
		sum%=998244353;
	}
	return sum;
}
int C(int x,int y)
{
	int sum=1;
	for(int i=1;i<=y;i++)
	{
		sum*=(x-i+1);
		sum/=i;
		sum%=998244353;
	}
	return sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		s[i]=s[i-1]+b[i]-'0';
		sum+=b[i]-'0';
	}
	if(sum<m)
	{
		cout<<0;
		return 0;
	}
	if(sum==n)
	{
		int cc=0;
		for(int i=m;i<=n;i++)
		{
			int num=C(n,i)*A(i,i);
			num%=998244353;
			cc+=num;
			cc%=998244353;
		}
		cout<<cc;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cf[a[i]]++;
	}
	for(int i=n-1;i>=0;i--)
	{
		cf[i]+=cf[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]=='1')q[++ccc]=cf[i-s[i]];
		if(q[ccc]==0)
		{
			ccc--;
			break;
		}
	}
	n=ccc;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		q[i]-=q[i+1];
	}
	if(q[m]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=m;i<=n;i++)
	{
		int num=C(n,i);
		dp[i+1]=1;
		for(int j=n;j>i;j--)
		{
			dp[i+1]+=q[j];
		}
		for(int j=i;j>=1;j--)
		{
			dp[j]=dp[j+1]*(q[j]+dp[j+1]-1);
			dp[j]%=998244353;
		}
		num*=dp[1];
		num%=998244353;
		ans+=num;
		ans%=998244353;
	}
	cout<<ans;
}

