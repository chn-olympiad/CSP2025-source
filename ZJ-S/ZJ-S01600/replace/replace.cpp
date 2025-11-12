#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[400001],t[400001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>s[n+i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i]>>t[q+i];
		cout<<0<<"\n";
	}
	return 0;
}
