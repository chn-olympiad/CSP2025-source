#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005,mod=998244353;
int n,m,sum,a[N],b[N],ans,num;
char c[N];
int p(int x)
{
	int res=1;
	for(int i=2;i<=x;i++)
		res=(res*i)%mod;
	return res;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='1')	sum++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)	num++; 
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]+=b[i-1];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]=='0')
				ans=(ans+b[i]*p(n-num-1)%mod)%mod;
		}
		cout<<ans;
		exit(0);
	}
	if(m==n)
	{
		if(sum==n&&num==0)	cout<<p(n);
		else				cout<<0;
		exit(0);
	}
	if(sum==n)
	{
		if(n-num<m)	cout<<0;
		else		cout<<p(n);
	}
	cout<<0; 
	return 0;
}
