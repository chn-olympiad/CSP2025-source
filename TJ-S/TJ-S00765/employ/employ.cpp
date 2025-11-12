#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505],num=0;
	long long ans=0;
	string s; 
	cin >> n >> m;
	cin >> s;
	bool f1=0,f2=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==0)
		{
			f1=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		if(c[i]==0)
		{
			f2=1;
			num++;
		}
	}
	if(m==n)
	{
		if(f1==0&&f2==0)
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
			cout << ans;
			return 0;
		}
		else
		{
			cout << 0;
		}
	}
	if(f1==0)
	{
		ans=1;
		if(n-num>=m)
		{
		    for(int i=1;i<=n;i++)
			{
				ans*=i;
				ans%=998244353;
			}
			cout << ans;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	else
	{
		cout << 0;
	} 
}
