#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool pd=true;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			pd=false;
		}
	}
	if(pd)
	{
		int gs=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				gs++;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
}
