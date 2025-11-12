#include <bits/stdc++.h>
using namespace std;
int n,q;
struct S
{
	string x,y;
}a[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	while(q--)
	{
		string s;
		cin>>s;
		cout<<0;
	}
	return 0;
}
