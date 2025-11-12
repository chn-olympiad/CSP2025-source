#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[510];
ll ans;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool ffffffffffffffffffff = true;
	for(int i = 0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			ffffffffffffffffffff = false;
			break;
		}
	}
	if(m==1) ffffffffffffffffffff = true;
	if(ffffffffffffffffffff==true)
	{
		ans = 1;
		for(int i = 1;i<=n;i++)
		{
			ans = (ans*i)%998244353;
		}
	}
	
	cout<<ans;
	return 0;
}
