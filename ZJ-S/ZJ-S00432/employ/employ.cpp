#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,s[512],flag=1;
string ex;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ex;ex=" "+ex;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<ex.size();i++)
		if(ex[i]=='0')
		{
			flag=0;
			break;
		}
	if(flag)
	{
		int ans=1;
		for(int i=n-m+1;i<=n;i++)
			ans=((1LL*ans*i/(i-n+m))%mod);
		cout<<ans;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
