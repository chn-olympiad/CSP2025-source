#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int c[505];
string s;
bool flag=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')flag=1;
	}
	if(n==m)
	{
		if(flag)
		{
			cout<<0<<endl;
		}
	}
	else if(!flag)
	{
		long long ans=1;
		int cnt;
		for(int i=1;i<=n;i++)
		{
			if(c[i]!=0)cnt++;
		}
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
