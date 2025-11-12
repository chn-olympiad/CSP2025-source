#include<bits/stdc++.h>
using namespace std;

const int N=1000;
const int mod=998244353;

long long n,m,p[N],ans=1;
string s;

signed main()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for (int i=m+1;i<=n;i++)
	{
		ans*=ans*i;
	}
	cout<<ans;
	
	return 0;
}
