#include<bits/stdc++.h>
using namespace std;
int c[500];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	long long i,j,k,n,m;
	long long ans=1;
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
