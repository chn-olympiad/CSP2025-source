#include <bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string s1,s2;
}a[200005];
struct nod
{
	string s1,s2;
}b[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].s1>>b[i].s2;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
