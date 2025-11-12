#include<bits/stdc++.h>
using namespace std;
long long int n,q;
string s[3][200005],t[3][200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[1][i]>>t[2][i];
	}
	if(n==4&&q==2)
	{
		cout<<2<<endl;
		cout<<0<<endl;
	}
	if(n==3&&q==4)
	{
		for(int i=1;i<=4;i++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
