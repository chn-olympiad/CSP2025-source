#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,ans=0,ans2=0;
string s;
long long a[600];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (i=0;i<s.size();i++)
	{
		if (s[i]=='1')
		{
			ans++;
		}
	}
	for (long long i=1;i<=ans;i++)
	{
		long long h=ans;
		for (long long j=1;j<=i;j++)
		{
			h*=(ans-j);
			h%=998244353;
		}
		ans2+=h;
		ans2%=998244353;
	}
	cout<<ans2;
	return 0;
}