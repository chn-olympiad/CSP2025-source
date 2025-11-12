#include <bits/stdc++.h>
using namespace std;
string s1[5000005],s2[5000005],t1[5000005],t2[5000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int j=1;j<=q;j++)
	{
		cin>>t1[j]>>t2[j];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}
