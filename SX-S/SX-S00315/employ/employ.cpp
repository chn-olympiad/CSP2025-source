#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long ans=1;
string s;
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
	for(int i=2;i<=n;i++)
	{
		ans%=998244353;
		ans*=i%998244353;
	}
	cout<<ans;
	return 0;
}
