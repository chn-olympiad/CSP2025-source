#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
long long a(long long q,long long w)
{
	long long ans=1;
	for (long long i=w;i>(w-q);i--)
	{
		ans*=i;
		ans%=998244353; 
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<a(m,n);
	return 0;
}
