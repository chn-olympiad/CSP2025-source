#include<bits/stdc++.h>
using namespace std;

struct str
{
	string s1,s2;
};

str a[2*100010],q[2*100010];

int n,q;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].s1>>q[i].s2;
	}
	return 0;
}
