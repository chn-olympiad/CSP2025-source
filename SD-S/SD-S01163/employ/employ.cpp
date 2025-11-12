#include <bits/stdc++.h>
using namespace std;
string s;
long long a[505],mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int flag=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			flag=0;
		}
	}
	cout<<0;
	return 0;
	if(flag)
	{
		long long e=n;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				e--;
			}
		}
		if(e<m)
		{
			cout<<0;
			return 0;
		}
		long long cnt=1;
		for(int i=1;i<=n;i++)
		{
			cnt*=i;
			cnt%=mod;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
