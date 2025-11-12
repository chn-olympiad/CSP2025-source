#include <bits/stdc++.h>
using namespace std;
const int N=1e5+12;
int n,m,a[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>a[N];
	}
	long long sum=1;
	for (int i=1;i<=n;i++)
	{
		sum=sum*i;
		sum=sum%998244353;
	}
	cout<<sum;
	return 0;
 } 
