#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,len,c[505],ans;
const int p=998244353;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	len=s.size();
	bool f=1;
	for(int i=0;i<len;i++)
	{
		if(s[i]!='1')
		{
			f=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(f)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%p;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
