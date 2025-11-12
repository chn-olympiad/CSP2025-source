//SN-J00948 蔡铭禹 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],w[5010][5010];

int qp(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=0,tp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=maxn;j++)
		{
			w[i][j]=w[i-1][j];
			tp=j-a[i];
			if(tp<0) w[i][j]=(w[i][j]+qp(2,i-1))%mod;
			else w[i][j]=(w[i][j]+w[i-1][tp])%mod;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=(ans+w[i][a[i+1]])%mod;
	}
	cout<<ans;
	return 0;
}
