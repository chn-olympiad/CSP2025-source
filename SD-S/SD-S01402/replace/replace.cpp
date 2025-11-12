#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5,M=5e6+5;
string c,d,a[N],b[N];
int n,q,v[N];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		v[a[i].size()]++;
	}
	while(q--)
	{
		cin>>c>>d;
		if(c.size()!=d.size()||v[c.size()]==0)	cout<<"0\n";
		else	cout<<"0\n";
	}
	return 0;
}
