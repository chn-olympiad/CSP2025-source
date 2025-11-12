#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;cin>>s;
	int pos=1;int pro=1;
	for(int i=1;i<=n;i++)
	{
		pro=(pro*n)%998244353;
	}
	cout<<pro;
	ios::sync_with_stdio(0);
	return 0;
}
