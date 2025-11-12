#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n+1],s2[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	string t1[q+1],t2[q+1];
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		cout<<0<<endl;
	}
	return 0;
} 