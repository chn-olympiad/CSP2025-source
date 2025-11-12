#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int c[510];
long long f(int n)
{
	long long ans=1;
	for(int i=2;i<=n;i++)
	{
		ans=ans*i%MOD;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m,a_jd=0;
	char s[510];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='1')
			a_jd++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(a_jd==n)
	{
		cout<<f(n);
		return 0;
	}
	if(m==n)
	{
		int b_jd++;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				b_jd++;
			}
		}
		if(b_jd==n)
		{
			cout<<f(n);
		}
		else
			cout<<0;
		return 0;
	}
	return 0;
}
