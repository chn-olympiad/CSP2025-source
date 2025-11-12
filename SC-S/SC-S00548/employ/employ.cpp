#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,m,a[100010];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long  ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}