#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const int MOD=998244353;
long long n,m,ans=1;
char s[N];
long long c[N];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
