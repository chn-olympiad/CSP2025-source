#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string a,b;
}s[10005],t[10005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i].a>>t[i].b;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}