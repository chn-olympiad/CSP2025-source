#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
const int N=505;
int c[N],n,m;
string s[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	int u=n/m;
	int sum=1;
	for(i=1;i<=u;i++)
	{
		sum*=m;
	}
	cout<<sum%mod;
	return 0;
}
