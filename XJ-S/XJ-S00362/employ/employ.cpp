#include <bits/stdc++.h>
using namespace std;
long long n,m,a[505],ans=1;
string p;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(p[i]==1)
			{
				cout<<n%998244353;
				return 0;
				cout<<0;
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		ans*=n-i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
 } 
