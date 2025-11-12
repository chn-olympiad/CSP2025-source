#include<bits/stdc++.h>
using namespace std;
long long n,s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		s=s*i;
		s=s%998244353;
	}
	cout<<s;
	return 0;
}