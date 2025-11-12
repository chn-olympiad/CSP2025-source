#include<bits/stdc++.h>
using namespace std;
int a[505],c[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n,m,ans=0;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<s.size();i++)
	{
		c[i]=s[i]-'0';
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int b;
		for(int j=1;j<i;j++)
		{
			if(a[j]==0)
			{
				b++;
			}
		}
		if(b>a[i])
		{
			a[i]=0;
		}
		if(c[i-1]==1)
		{
			a[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			sum++;
		}
	}
	if(sum>=m)
	{
		ans++;
	}
	cout<<ans%998244353;
	return 0;
}
