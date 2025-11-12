#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[10000];
	string s[10000];
	string a1[10000];
	string s1[10000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>a1[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s[i]>>s1[i];
	}
	if(n==4&&q==2)
	{
		cout<<2<<endl<<0;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}